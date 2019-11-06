package daniel.example.mysms;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;

import android.Manifest;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.view.*;
import android.widget.*;

public class MainActivity extends AppCompatActivity {
    private Button bt;
    private EditText phoneEditText;
    private EditText messageEditText;
    private TextView textView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        bt = findViewById(R.id.button);
        phoneEditText = findViewById(R.id.phoneet);
        messageEditText = findViewById(R.id.messageet);
        textView = findViewById(R.id.status);

        bt.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if (ActivityCompat.checkSelfPermission(MainActivity.this,
                        Manifest.permission.SEND_SMS) != PackageManager.PERMISSION_GRANTED) {
                    ActivityCompat.requestPermissions(MainActivity.this,
                            new String[]{Manifest.permission.SEND_SMS},
                            1);
                } else {
                    sendSms();
                }
            }
        });
    }

    private void sendSms() {
        String phone_Num = phoneEditText.getText().toString();
        String send_msg = messageEditText.getText().toString();
        try {
            SmsManager sms = SmsManager.getDefault();
            System.out.println(phone_Num + ", " + send_msg);
            sms.sendTextMessage(phone_Num, null, send_msg, null, null);
            textView.setText("Message sent!");
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}
