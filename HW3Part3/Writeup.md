# HW3 Part 3 Lab

## Step 1: APK package name
com.example.cs493.homework as shown in the Java decompiler

## Step 2: Permissions used in APK
As copied from the mainfest verbatim (after using the APK Tool):
    <uses-permission android:name="android.permission.GET_ACCOUNTS"/>
    <uses-permission android:name="android.permission.READ_PROFILE"/>
    <uses-permission android:name="android.permission.READ_CONTACTS"/>
    <uses-permission android:name="android.permission.CALL_PHONE"/>
    <uses-permission android:name="android.permission.SEND_SMS"/>
    <uses-permission android:name="android.permission.ACCESS_FINE_LOCATION"/>

Permissions used are GET_ACCUONTS, READ_PROFILE, READ_CONTACTS, CALL_PHONE, SEND_SMS, AND ACCESS_FINE_LOCATION

## Step 3: Crack the password
### Process to get password:
1. Add the string "@CS493" to the end of the username string
2. Multiply each character of the string by j (initialized at 1) and then mod it with 12345678
3. The final integer is the password

* Step 2 is similar to multiplying all of the character values of the string together and then modding the result with 12345678

Example below:
Username=Daniel
Password=9067536
