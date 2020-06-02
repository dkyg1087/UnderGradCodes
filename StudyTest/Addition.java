package TestStudy;
import javax.swing.JOptionPane;

public class Addition{
    public static void main(String[] args){
        String firstNumber=JOptionPane.showInputDialog("Enter first integer.");
        String secondNumber=JOptionPane.showInputDialog("Enter second integer.");
        int number1=Integer.parseInt(firstNumber),number2=Integer.parseInt(secondNumber);
        JOptionPane.showMessageDialog(null,"The sum is "+(number1+number2),"Sum of two Integer",JOptionPane.PLAIN_MESSAGE);
    }
}