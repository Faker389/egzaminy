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

namespace paszporty
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }
        private void NumberTextBox_LostFocus(object sender, RoutedEventArgs e)
        {
            TextBox tb = sender as TextBox;
            string value = tb.Text;
            if (value != "111" && value != "000" && value != "333") return;
            try
            {

                Image1.Source = new BitmapImage(new Uri($"pack://application:,,,/paszporty;component/{value}-zdjecie.jpg"));
                Image2.Source = new BitmapImage(new Uri($"pack://application:,,,/paszporty;component/{value}-odcisk.jpg"));
            }
            catch (Exception ex){
                MessageBox.Show(ex.Message);
            }
        }
        string checkEyeColor()
        {
            string eyeColor="";
            if (RadioButton1.IsChecked == true) { eyeColor = "niebieskie"; }
            if (RadioButton2.IsChecked == true) { eyeColor = "zielone"; }
            if (RadioButton3.IsChecked == true) { eyeColor = "piwne"; }
            return eyeColor;
        }
        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string  nameValue, lastNameValue,eyeColor;
            nameValue = NameTextBox.Text.Trim();
            lastNameValue = LastNameTextBox.Text.Trim();
            eyeColor = checkEyeColor();
            if(nameValue==""||lastNameValue==""||eyeColor=="")
            {
                MessageBox.Show("Wprowadź dane");
                return;
            }
            MessageBox.Show($"{nameValue} {lastNameValue} kolor oczu {eyeColor}");
        }
    }
}
