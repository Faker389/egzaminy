using System;
using System.Collections.Generic;
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

namespace hasla
{
    public partial class MainWindow : Window
    {
        static string letters = "abcdefghijklmnoprstuvyzxqw";
        static string digits = "0123456789";
        static string specialCharacters = "!@#$%^&*()_+-=";
        static string generatedPassword = "";
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string passworLength = PasswordLength.Text;
            if(passworLength.Length == 0)
            {
                MessageBox.Show("Wprowadź długość hasła");
                return;
            }
            string passwordResult = "";
            Random random = new Random();
            int passwordLengthParsed = Convert.ToInt32(passworLength);
            if (LoweAndUpperCharacters.IsChecked == true)
            {
                passwordResult += letters[random.Next(letters.Length)].ToString().ToUpper();
                passwordLengthParsed--;
            }
            if (Digits.IsChecked == true) 
            {
                passwordResult += digits[random.Next(digits.Length)];
                passwordLengthParsed--; 
            }
            if (SpecialCharacters.IsChecked == true)
            {
                passwordResult += specialCharacters[random.Next(specialCharacters.Length)];
                passwordLengthParsed--;
            }
            for(int x = 0; x < passwordLengthParsed; x++)
            {
                passwordResult += letters[random.Next(letters.Length)];
            }
            generatedPassword = passwordResult;
            MessageBox.Show(passwordResult);
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            string name, lastname, position;
            name = NameTextBox.Text;
            lastname = LastNameTextBox.Text;
            position = Position.Text ;
            MessageBox.Show($"Dane pracownika: {name} {lastname} {position} Hasło: {generatedPassword}");
        }
    }
}
