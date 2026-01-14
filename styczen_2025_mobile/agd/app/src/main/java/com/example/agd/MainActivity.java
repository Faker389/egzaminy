package com.example.agd;

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
    EditText washingProgram;
    Button confirmButton,toggleVacumButton;
    TextView washingProgramOutput,vaccumOutput;
    static boolean isVacumOn=false;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        initializeElements();
        setOnClickListeners();
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }
    private  void initializeElements(){
        washingProgram=findViewById(R.id.pranieEditText);
        confirmButton=findViewById(R.id.confrimButton);
        washingProgramOutput=findViewById(R.id.pranieOutputText);
        toggleVacumButton=findViewById(R.id.toggleVacumButton);
        vaccumOutput=findViewById(R.id.vaccumOutput);
    }
    private  void setOnClickListeners(){
        confirmButton.setOnClickListener(v -> {
            String editTextOutput = washingProgram.getText().toString();
            int washingProgramInt = Integer.parseInt(editTextOutput);
            if(washingProgramInt>=1&&washingProgramInt<=12){
                washingProgramOutput.setText("Numer prania: "+washingProgramInt);
            }
        });
        toggleVacumButton.setOnClickListener(v->{
            if(!isVacumOn){
                toggleVacumButton.setText("Wyłącz");
                vaccumOutput.setText("Odkurzacz: włączony");
            }else{
                toggleVacumButton.setText("Włącz");
                vaccumOutput.setText("Odkurzacz: wyłączony");
            }
            isVacumOn=!isVacumOn;
        });
    }
}