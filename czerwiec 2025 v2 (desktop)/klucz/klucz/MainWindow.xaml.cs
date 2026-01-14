using Microsoft.Win32;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;
using static System.Net.Mime.MediaTypeNames;

namespace klucz
{
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        public void cesarHashing(int key,string text)
        {
            if (key == 0||text=="")
            {
                textOutput.Text = text;
                return;
            }
            string hashedText = "";
            for (int x = 0; x < text.Length; x++)
            {
                int currentAsciiVal = Convert.ToInt16((char)text[x]);
                if ((currentAsciiVal < 97 || currentAsciiVal > 122) && currentAsciiVal != 32)
                {
                    MessageBox.Show("Text can only contain lower letters");
                    return;
                }
                int movedChar = 32;
                if (currentAsciiVal != 32)
                {
                    if (key > 0)
                    {
                        if (currentAsciiVal + key > 122) movedChar = Convert.ToChar(((currentAsciiVal + key) - 123) + 97);
                        else movedChar = Convert.ToChar(currentAsciiVal + key);
                    }
                    else
                    {
                        if (currentAsciiVal + key < 97) movedChar = Convert.ToChar(((currentAsciiVal + key) - 97) + 122);
                        else movedChar = Convert.ToChar(currentAsciiVal + key);
                    }
                }
                hashedText += Convert.ToChar(movedChar);
            }
            textOutput.Text= hashedText;
        }
        private void hashButton_Click(object sender, RoutedEventArgs e)
        {
            string text = textInput.Text;
            int key;
            try
            {
                key=Convert.ToInt16(keyInput.Text);
                cesarHashing(key, text);
            }
            catch (Exception)
            {
                key = 0;
                cesarHashing(key, text);
            }
        }

        private void saveToFile_Click(object sender, RoutedEventArgs e)
        {
            SaveFileDialog saveFileDialog = new SaveFileDialog { 
                DefaultExt =".txt"
            };
            if (saveFileDialog.ShowDialog() == true)
            {
                string dataToAppend = textOutput.Text;
                File.WriteAllText(
                    saveFileDialog.FileName,
                    dataToAppend,
                    Encoding.UTF8
                );
            }
        }
    }
}
