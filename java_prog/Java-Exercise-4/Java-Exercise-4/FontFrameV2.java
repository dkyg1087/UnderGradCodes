package ntou.cs. java2020.ex4;

// Displays text using font.
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

public class FontFrameV2 extends JFrame implements ActionListener {
	private JButton increaseButton; // button to increase font size
	private JButton decreaseButton; // button to decrease font size
	private JTextArea text; // displays example text
	private int fontSize = 20; // current font size

	public FontFrameV2() {
		super("Font Test");

		// create buttons and add this as an action listener
		increaseButton = new JButton("Increase font size");
		increaseButton.addActionListener(this);
		decreaseButton = new JButton("Decrease font size");
		decreaseButton.addActionListener(this);

		// create text area and set initial font
		text = new JTextArea("Test");
		text.setFont(new Font("Calibri", Font.PLAIN, fontSize));

		// add GUI components to frame
		JPanel panel = new JPanel(); // used to get proper layout
		panel.add(decreaseButton);
		panel.add(increaseButton);

		add(panel, BorderLayout.NORTH); // add buttons at top
		add(new JScrollPane(text)); // allow scrolling
	}

	// change font size when user clicks on a button
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

} // end class EcofontFrame
