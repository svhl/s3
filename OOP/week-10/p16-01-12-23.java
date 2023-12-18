// write a program that works as a simple calculator to calculate area of a circle, rectangle & triangle

import java.awt.event.*;
import java.awt.*;

class Calculator extends Frame implements ActionListener
{
	Button cir, rec, tri;
	TextField num1, num2, res;
	Label heading;

	Calculator()
	{
		super("Calculator");
		cir = new Button("Circle");
		rec = new Button("Rectangle");
		tri = new Button("Triangle");
		heading = new Label("Enter 2 numbers");
		num1 = new TextField(10);
		num2 = new TextField(10);	
		res = new TextField(10);
		add(cir);
		add(rec);
		add(tri);
		add(num1);
		add(num2);
		add(res);
		setLayout(null);
		cir.setBounds(10, 100, 60, 20);
		rec.setBounds(80, 100, 60, 20);
		tri.setBounds(150, 100, 60, 20);
		num1.setBounds(10, 40, 200, 20);
		num2.setBounds(10, 70, 200, 20);
		res.setBounds(10, 130, 200, 20);
		heading.setBounds(10, 10, 200, 20);
		setSize(220, 220);
		setVisible(true);
		cir.addActionListener(this);
		rec.addActionListener(this);
		tri.addActionListener(this);
	}

	public void actionPerformed(ActionEvent ae)
	{
		Object source = ae.getSource();
		int n1, n2;
		double a;
		n1 = Integer.parseInt(num1.getText());

		if(source == cir)
		{
			a = 3.14 * n1 * n1;
			res.setText(Double.toString(a));
		}

		n2 = Integer.parseInt(num2.getText());

		if(source == rec)
		{
			a = n1 * n2;
			res.setText(Double.toString(a));
		}
		
		if(source == tri)
		{
			a = 0.5 * n1 * n2;
			res.setText(Double.toString(a));
		}
	}

	public static void main(String args[])
	{
		Calculator c = new Calculator();
	}
}
