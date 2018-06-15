/*
 * Yixing Zheng
 * 2293298
 * zheng129@mail.chapman.edu
 * CPSC 236 - 03
 * Project 4
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Project4{
    public partial class Form2 : Form{

        Form1 formref;
        public Form2(Form1 form1){
            InitializeComponent();

            this.formref = form1;
        }

        private void Form2_FormClosing(object sender, FormClosingEventArgs e){
            // To access Form1's labelForm2Response object, in Form1.Designer.cs, change the object from private to public
            this.formref.labelExtra.Text = textBoxExtra.Text;
            this.Close();
        }

        private void buttonCloseForm2_Click(object sender, EventArgs e){
            // Trigger the Close event for Form2
            this.Close();
        }
    }
}
