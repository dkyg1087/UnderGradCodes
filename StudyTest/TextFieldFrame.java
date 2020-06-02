package TestStudy;

import java.awt.event.ActionEvent;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JTextField;
import java.awt.FlowLayout;
import java.awt.event.ActionListener;
import javax.swing.JPasswordField;
import javax.swing.JOptionPane;

public class TextFieldFrame extends JFrame {
    private final JTextField textField1;
    private final JTextField textField2;
    private final JTextField textField3;
    private final JPasswordField passwordField;
    public TextFieldFrame(){
        super("Testing JTextField amd JPasswordField");
        setLayout(new FlowLayout());
        textField1 = new JTextField(10);
        add(textField1);
        textField2 = new JTextField("Enter text here");
        add(textField2);
        textField3 = new JTextField("Uneditable Text Field",50);
        textField3.setEditable(false);
        add(textField3);
        passwordField = new JPasswordField("Hidden Text");
        add(passwordField);
        TextFieldHandler handler = new TextFieldHandler();
        textField1.addActionListener(handler);
        textField2.addActionListener(handler);
        textField3.addActionListener(handler);
    }
    private class TextFieldHandler implements ActionListener {
        @Override
        public void actionPerformed(ActionEvent event){
            String string="";
            if(event.getSource()==textField1)string=String.format("textField1: %s",event.getActionCommand());
            else if(event.getSource()==textField2)string=String.format("textField2: %s",event.getActionCommand());
            else if(event.getSource()==textField3)string=String.format("textField3: %s",event.getActionCommand());
            JOptionPane.showMessageDialog(null,string);
        }
    }
}