// write a program to receive an integer through the 1st text field, check if it's a perfect number, & display the result in the 2nd text field
// if the number isn't perfect, display sum of digits

import javax.swing.*;
import java.awt.event.*;

class PerfectChecker extends JFrame implements ActionListener
{
	JButton ch;
	JTextField num, res;
	JLabel heading;

	PerfectChecker()
	{
		super("Perfect Checker");
		ch = new JButton("Check");
		heading = new JLabel("Enter number");
		num = new JTextField(10);
		res = new JTextField(10);
		add(heading);
		add(ch);
		add(num);
		add(res);
		setLayout(null);
		ch.setBounds(10, 70, 200, 20);
		num.setBounds(10, 40, 200, 20);
		res.setBounds(10, 100, 200, 20);
		heading.setBounds(10, 10, 200, 20);
		setSize(220, 220);
		setVisible(true);
		setDefaultCloseOperation(EXIT_ON_CLOSE);
		ch.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae)
	{
		Object source = ae.getSource();
		int n, s = 0;
		n = Integer.parseInt(num.getText());

		if(source == ch)
		{
			for(int i = 1; i <= n / 2; i++)
			{
				if(n % i == 0)
				{
					s = s + i;
				}
			}

			if(s == n)
			{
				res.setText("Perfect number");
			}

			else
			{
				int m = n;
				s = 0;

				while(m > 0)
				{
					int d = m % 10;
					s = s + d;
					m = m / 10;
				}

				res.setText(Integer.toString(s));
			}
		}
	}

	public static void main(String args[])
	{
		PerfectChecker p = new PerfectChecker();
	}
}
