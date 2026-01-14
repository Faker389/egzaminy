package com.example.domek;

import android.os.Bundle;
import android.widget.Button;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {
    Button likeButton,removeLikeButton;
    TextView likeCount;
    static int likeCounter=0;
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
        likeButton=findViewById(R.id.likeButton);
        removeLikeButton=findViewById(R.id.removeLikeButton);
        likeCount=findViewById(R.id.likesCount);
        likeButton.setOnClickListener(v->{
            likeCounter++;
            likeCount.setText(likeCounter+" polubień");
        });
        removeLikeButton.setOnClickListener(v->{
            if(likeCounter-1<0) likeCounter=0;
            else likeCounter-=1;
            likeCount.setText(likeCounter+" polubień");
        });
    }
}