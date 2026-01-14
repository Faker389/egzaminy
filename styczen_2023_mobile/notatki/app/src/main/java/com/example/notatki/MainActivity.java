package com.example.notatki;

import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.LinearLayout;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private ArrayList<String> lista = new ArrayList<>();
    private LinearLayout mainList;
    private EditText noteEditText;
    private Button addNote;
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
    private  void generateNotes(){
        mainList.removeAllViews();
        lista.forEach((e)->{
            TextView txt = new TextView(this);
            txt.setText(e);
            txt.setPadding(0,0,0,10);
            View devider = new View(this);
            devider.setMinimumHeight(2);
            devider.setBackgroundColor(getResources().getColor(R. color. black));
            mainList.addView(txt);
            mainList.addView(devider);
        });
    }
    private  void initializeElements(){
        mainList=findViewById(R.id.mainList);
        noteEditText=findViewById(R.id.noteEditText);
        addNote=findViewById(R.id.button);
        addNote.setOnClickListener((e)->{
            String noteContent = noteEditText.getText().toString();
            lista.add(noteContent);
            generateNotes();
            noteEditText.setText("");
        });
        lista.add("Zakupy: chleb, masło, ser");
        lista.add("Do zrobienia: obiad, umyć podłogi");
        lista.add("Do weekend: kino, spacer z psem");
        generateNotes();
    }
}