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

namespace RGB
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        static byte r, g, b;
        
        public MainWindow()
        {
            InitializeComponent();
        }

        private void Slider_ValueChanged(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int currentVal = (int)e.NewValue;
            RVal.Content = currentVal.ToString();
            r = (byte)e.NewValue;
            g = (byte)GSlider.Value;
            b = (byte)BSlider.Value;
            Brush brush = new SolidColorBrush(Color.FromRgb(r, g, b));
            TopRectangle.Fill = brush;
        }

        private void Slider_ValueChanged_1(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int currentVal = (int)e.NewValue;
            GVal.Content = currentVal.ToString();
            r = (byte)RSlider.Value;
            g = (byte)e.NewValue;
            b = (byte)BSlider.Value;
            Brush brush = new SolidColorBrush(Color.FromRgb(r, g, b));
            TopRectangle.Fill = brush;
        }

        private void Slider_ValueChanged_2(object sender, RoutedPropertyChangedEventArgs<double> e)
        {
            int currentVal = (int)e.NewValue;
            BVal.Content = currentVal.ToString();
            r = (byte)RSlider.Value;
            g = (byte)GSlider.Value;
            b = (byte)e.NewValue;
            Brush brush = new SolidColorBrush(Color.FromRgb(r, g, b));
            TopRectangle.Fill = brush;
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            string RValue,GValue, BValue;
            RValue = ((int)RSlider.Value).ToString();
            GValue = ((int)GSlider.Value).ToString();
            BValue = ((int)BSlider.Value).ToString();
            BottomRGBLabel.Content = $"{RValue}, {GValue}, {BValue}";
            r = (byte)RSlider.Value;
            g = (byte)GSlider.Value;
            b = (byte)BSlider.Value;
            Brush brush = new SolidColorBrush(Color.FromRgb(r, g, b));
            BottomRGBLabel.Background = brush;
        }
    }
}
