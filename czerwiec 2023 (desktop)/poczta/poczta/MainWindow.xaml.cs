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

namespace poczta
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

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string postCode = PostCode.Text;
            if (postCode.Length != 5)
            {
                MessageBox.Show("Nieprawidłowa liczba cyfr w kodzie pocztowym");
                return;
            }
            try
            {
                int postCodeParsed = int.Parse(postCode);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Kod pocztowy powinien składać sie z samych cyfr");
                return;
            }
            MessageBox.Show("Dane przesyłki zostały wprowadzone");
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            if (RadioButton1.IsChecked == true)
            {
                ImagePost.Source = new BitmapImage(new Uri("pack://application:,,,/pocztowka.png"));
                Price.Content = "Cena: 1 zł";
                return;
            }
            if (RadioButton2.IsChecked == true)
            {
                ImagePost.Source = new BitmapImage(new Uri("pack://application:,,,/list.png"));
                Price.Content = "Cena: 1,5 zł";
                return;
            }
            if (RadioButton3.IsChecked == true)
            {
                ImagePost.Source = new BitmapImage(new Uri("pack://application:,,,/paczka.png"));
                Price.Content = "Cena: 10 zł";
                return;
            }
        }
    }
}
