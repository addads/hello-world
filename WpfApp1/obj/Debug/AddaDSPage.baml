   M S B A M L   `   `   `  ����B  >WpfApp1, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null!clr-namespace:WpfApp1WpfApp1  5          AddaDS.AddaDSPage   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      'localclr-namespace:WpfApp1     5        N� Title$  AddaDS - SuperPage��5	      .��5      �  � 	Resources 5   
      typeItemTemplate �� XPath  amountItemTemplate��%�   &	        &	 I     �� 5      .R�5      �� ��6   �� $ @ExpenseType��5      �� 5      .R�5      �� ��6   �� $ @ExpenseAmount��5      5      ��5   
   �� 5       �� ImageSource$U OC:\Users\ACalota\source\repos\WpfApp1\Afternoon-Delight-Unicorn-Rainbow-Sex.jpg��6    � ColumnDefinitions 5   
   �� 5      $	��230 �6   �� 5       � RowDefinitions 5   
   �� 5      $
��Auto �6   �� 5      .+�5#   
   �� $��1��6     headerTextStyle#��[ 6    .��6I   This is a strange page5%      � 5&   
   $��-114,10,10,10q�6   $��0��6&   $��1��66    J� RenderTransformOrigin$ 0.491,0.496&�6C    5(      �� 5)      �� 5*       5,      �� 5-      $
��Auto �6    $��47��6.   �� 5.      $
��Auto �6    $��40��6.   �� 5/      .+�53      �� $��1��6   $��0��6)    �� Orientation$ 
Horizontal=�66   .+�54      ��   
labelStyle#��[ 6   .��6<   Name:6C   �� 55      #��[ 6   ��6<   �� $ @Name��6^   56      �� 58      $��1��6   $��1��6)   $ 
Horizontal=�59      .+�5:      �� #��[ 6   .��6<   Reason to live:6M   �� 5;      #��[ 6   ��6<   �� $ @Department��6d   5<      � 5>      $��1��6   $��2��6#   $	��Top=�60   $
��Left=�5?      $��37��6(   $	��105��64   .+�5B      &   System.Windows.Controls.DataGrid    columnHeaderStyle   ColumnHeaderStyle# [ 6A   	   AutoGenerateColumns	 .  
   RowHeaderWidth$
 0Q�6�   $��
0,0,-130,0q�6�   ��6   �� $ Expense��   Columns 5D      4  .System.Windows.Controls.DataGridTemplateColumn  5E      ,  &System.Windows.Controls.DataGridColumn   Header$ 	Something��61      CellTemplate# [  6D     5F      $ Dunno��61   # [ 6@   5I      5J      5K      5L      5M      