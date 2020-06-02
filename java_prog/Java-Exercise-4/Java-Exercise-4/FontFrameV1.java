package ntou.cs. java2020.ex4;

import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTextArea;

public class FontFrameV1 {
	private JFrame appFrame;
	private JButton increaseButton; // button to increase font size
	private JButton decreaseButton; // button to decrease font size
	private JTextArea text; // displays example text
	private int fontSize = 20; // current font size

	public FontFrameV1() {
		appFrame = new JFrame("Font Test");

		ActionListener listener = new MyListener();

		// create buttons and add this as an action listener
		increaseButton = new JButton("Increase font size");
		increaseButton.addActionListener(listener);
		decreaseButton = new JButton("Decrease font size");
		decreaseButton.addActionListener(listener);

		// create text area and set initial font
		text = new JTextArea("Test");
		text.setFont(new Font("Calibri", Font.PLAIN, fontSize));

		// add GUI components to frame
		JPanel panel = new JPanel(); // used to get proper layout
		panel.add(decreaseButton);
		panel.add(increaseButton);
		
		appFrame.add(panel, BorderLayout.NORTH); // add buttons at top
		appFrame.add(new JScrollPane(text)); // allow scrolling
	}

	private class MyListener implements ActionListener {
		@Override
		public void actionPerformed(ActionEvent event) {
			if(event.getSource() ==increaseButton){
				if(fontSize >=160){
					JOptionPane.showMessageDialog(null,"No, it cannot be larger");
				}
				else{
					fontSize =fontSize+2;
				}
				text.setFont(new Font("Calibri",Font.PLAIN,fontSize));
			}
			else if(event.getSource() ==decreaseButton){
				if(fontSize<=8){
					JOptionPane.showMessageDialog(null,"No, it cannot be smaller");
				}
				else{
					fontSize=fontSize-2;
				}
				text.setFont(new Font("Calibri",Font.PLAIN,fontSize));
			}
		}
	}
	
	public JFrame getFrame() {
		return appFrame;
	}
}
