package com.example.domek;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    EditText email,password,confrimPassword;
    Button submitButton;
    TextView resultTextView;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        initializeElements();
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }
    void initializeElements(){
        email=findViewById(R.id.emailEditText);
        resultTextView=findViewById(R.id.resultTextView);
        password=findViewById(R.id.passwordEditText);
        confrimPassword=findViewById(R.id.confirmEditText);
        submitButton=findViewById(R.id.confirmButton);
        submitButton.setOnClickListener(view -> {
           String emailText,passwordText,confirmPasswordText;
           emailText=email.getText().toString().trim();
           passwordText=password.getText().toString().trim();
           confirmPasswordText=confrimPassword.getText().toString().trim();
           if(!emailText.contains("@")) {
               resultTextView.setText("Nieprawidłowy adres e-mail");
               return;
           }
           if(!passwordText.equals(confirmPasswordText)) {
               resultTextView.setText("Hasła się różnią");
               return;
           }
           resultTextView.setText("Witaj "+emailText);
        });
    }
}