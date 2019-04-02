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
using System.Windows.Forms;
using System.Timers;

namespace AddaDS
{
    /// <summary>
    /// Interaction logic for AddaDSHome.xaml
    /// </summary>
    public partial class AddaDSHome : Page
    {

        private System.Timers.Timer timer;
        //System.Windows.Forms.ProgressBar ProgressBar;
        public AddaDSHome()
        {
            InitializeComponent();
            System.Windows.Forms.ProgressBar ProgressBar = new System.Windows.Forms.ProgressBar();

            timer = new System.Timers.Timer(1000);

            timer.Elapsed += new ElapsedEventHandler(timer_Elapsed);
            timer.Start();
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            AddaDSPage addadsPage = new AddaDSPage(this.peopleListBox.SelectedItem);
            this.NavigationService.Navigate(addadsPage);
        }

        void timer_Elapsed(object sender, ElapsedEventArgs e)
        {
            this.Dispatcher.Invoke(System.Windows.Threading.DispatcherPriority.Normal, (Action)(() =>
            {
                if (ProgressBar.Value < 30)
                {
                    ProgressBar.Value += 1;
                }
                else
                {
                    timer.Stop();
                }
            }));
        }
    }
}
