   M S B A M L   `   `   `  ����B  >WpfApp1, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null!clr-namespace:WpfApp1WpfApp1  5          AddaDS.AddaDSHome   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      'localclr-namespace:WpfApp1     5        N� Title$  AddaDS - Home��5	      .��5      � $��
10,0,10,10q�6    � 	Resources 5   
      nameItemTemplate �� XPath  ExpenseDataSource � XPath��%�  &	        &	 B     �� 5      .R�5      �� ��6   �� $ @Name��5      � 5      $ Expenses��68   .��5      ��<Expenses xmlns="">
                        <Person Name="Hello" Department="You">
                            <Expense ExpenseType="Hi" ExpenseAmount="2" />
                            <Expense ExpenseType="Hello" ExpenseAmount="5" />
                        </Person>
                        <Person Name="Bye" Department="Still you">
                            <Expense ExpenseType="Go away" ExpenseAmount="7" />
                            <Expense ExpenseType="Stay away" ExpenseAmount="9" />
                        </Person>
                        <Person Name="Nananana" Department="Batman">
                            <Expense ExpenseType="Happy" ExpenseAmount="5" />
                            <Expense ExpenseType="Dark" ExpenseAmount="4" />
                            <Expense ExpenseType="Good" ExpenseAmount="4" />
                        </Person>
                        <Person Name="Why" Department="Me">
                            <Expense ExpenseType="No" ExpenseAmount="2" />
                        </Person>
                    </Expenses>        5)      5*      ��5+   
   �� 5,       �� ImageSource$U OC:\Users\ACalota\source\repos\WpfApp1\Afternoon-Delight-Unicorn-Rainbow-Sex.jpg��6    � ColumnDefinitions 5.   
   �� 5/      $	��230 �6   �� 50       � RowDefinitions 53   
   �� 54      �� 55      $
��Auto �6   �� 56      �� 57      $
��Auto �6   .+�5:   
   �� $��0��6     headerTextStyle#��[ 6    .��6J   
Hello :(5<      � 5>   
   -   5         �Name$ ProgressBar��5>   G   $	��300��6   $��25��6"    � Minimum$ 0Q�6.   	 � Maximum$	 30Q�6:   6^   �� 5?   
   $��1��6   $��1��6!     listHeaderStyle#��[ 6.   ._�5@      ��   listHeaderTextStyle#��[ 6   .��6A   That's cute6N   5A      �� 5B   
   -   5        $��peopleListBox��5B      $��1��6'   $��2��67   #��[  5D   
   ��5C   
   �� 
 �� Source#
 [ $ Person��5E      �� 5J   
   -   5        $��1��5J      $��3��6!     buttonStyle#��[ 6C   .��6h   S.O.S.6p   5L      5M      