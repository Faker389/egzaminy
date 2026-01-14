package com.example.formularz;

import android.os.Bundle;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.SeekBar;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;
import java.util.List;

class Pet{
    String name;
    int age;
    Pet(String n,int a){
        this.name=n;
        this.age=a;
    }
}
public class MainActivity extends AppCompatActivity {
    LinearLayout petsLayout;
    static ArrayList<Pet> petsList =new ArrayList();
    SeekBar petAgeSlider;
    TextView ageText,outputText;
    Button confirm;
    EditText nameEditText,appointmentGoalEditText,appointmentTimeEditText;
    static String currentPetSelected="";
    static  int currentAge=0;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        initializeElements();
        addOnClickListeners();
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }
    private void addOnClickListeners(){
        petsList.forEach(e->{
            TextView txt = new TextView(this);
            txt.setText(e.name);
            txt.setOnClickListener(v->{
                petAgeSlider.setMax(e.age);
                currentPetSelected=e.name;
            });
            petsLayout.addView(txt);
        });
        confirm.setOnClickListener(v->{
            String ownerName = nameEditText.getText().toString();
            String appointmentGoal = appointmentGoalEditText.getText().toString();
            String appointmentTime = appointmentTimeEditText.getText().toString();
            outputText.setText(ownerName+ ","+currentPetSelected + ", "+currentAge+", "+appointmentGoal+", "+appointmentTime);
        });
        petAgeSlider.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {

            @Override
            public void onProgressChanged(SeekBar seekBar, int i, boolean b) {
                ageText.setText("Ile ma lat? "+i);
                currentAge=i;
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });
    }
    private  void initializeElements(){
        petsLayout = findViewById(R.id.petsLayout);
        petAgeSlider=findViewById(R.id.seekBar2);
        ageText=findViewById(R.id.ageText);
        confirm=findViewById(R.id.button);
        nameEditText=findViewById(R.id.nameEditText);
        appointmentGoalEditText=findViewById(R.id.appointmentGoalEditText);
        appointmentTimeEditText=findViewById(R.id.appointmentTimeEditText);
        outputText=findViewById(R.id.outputText);
        petsList.add(new Pet("Pies",18));
        petsList.add(new Pet("Kot",20));
        petsList.add(new Pet("Świnka morska",9));
    }
}