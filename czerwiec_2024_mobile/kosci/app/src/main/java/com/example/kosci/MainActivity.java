package com.example.kosci;

import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

import java.util.Random;


public class MainActivity extends AppCompatActivity {
    Button ThrowDice,resetGame;
    TextView singleGameResult,totalGameResult;
    int gameScore=0;
    final int imageTagIds[] = {R.id.Dice1, R.id.Dice2, R.id.Dice3, R.id.Dice4, R.id.Dice5, R.id.Dice6};
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        EdgeToEdge.enable(this);
        setContentView(R.layout.activity_main);
        initializeElements();
        addButtonListeners();
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main), (v, insets) -> {
            Insets systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars());
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom);
            return insets;
        });
    }
    void updateImages(int tab[]){
        ImageView currentDice;
        int imagesFromDrawable[] = {R.drawable.k1,R.drawable.k2,R.drawable.k3,R.drawable.k4,R.drawable.k5,R.drawable.k6};
        for(int x=0;x<6;x++) {
            currentDice=findViewById(imageTagIds[x]);
            currentDice.setImageResource(imagesFromDrawable[tab[x]-1]);
        }
    }
    int calculatePoints(int tab[], int n) {
        int points = 0;
        for (int number = 1; number <= 6;number++) {
            int count = 0;
            for (int x = 0;x < n;x++) {
                if (tab[x] == number) count++;
            }
            if (count >= 2) {
                points += number * count;
            }
        }
        return points;
    }
    void initializeElements(){
        singleGameResult= findViewById(R.id.textThrowResult);
        totalGameResult = findViewById(R.id.textGameResult);
        resetGame=findViewById(R.id.buttonReset);
        ThrowDice=findViewById(R.id.buttonThrowDice);
    }
    void addButtonListeners(){
        ThrowDice.setOnClickListener(v -> {
            int[] tab = new int[6];
            Random random = new Random();

            for (int i = 0; i < 6; i++) {
                tab[i] = random.nextInt(6) + 1;
            }
            updateImages(tab);
            int points = calculatePoints(tab, 6);
            singleGameResult.setText("Wynik tego losowania: "+points);
            gameScore+=points;
            totalGameResult.setText("Wynik gry: "+gameScore);
        });
        resetGame.setOnClickListener(v->{
            singleGameResult.setText("Wynik tego losowania: 0");
            totalGameResult.setText("Wynik gry: 0");
            gameScore=0;
            ImageView currentDice;
            for(int x=0;x<6;x++){
                currentDice=findViewById(imageTagIds[x]);
                currentDice.setImageResource(R.drawable.question);
            }
        });
    }
}