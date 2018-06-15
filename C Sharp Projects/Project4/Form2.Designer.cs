/*
 * Yixing Zheng
 * 2293298
 * zheng129@mail.chapman.edu
 * CPSC 236 - 03
 * Project 4
 */

namespace Project4
{
    partial class Form2
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxExtra = new System.Windows.Forms.TextBox();
            this.buttonExtra = new System.Windows.Forms.Button();
            this.labelBook = new System.Windows.Forms.Label();
            this.labelMovie = new System.Windows.Forms.Label();
            this.labelCD = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // textBoxExtra
            // 
            this.textBoxExtra.Location = new System.Drawing.Point(48, 61);
            this.textBoxExtra.Name = "textBoxExtra";
            this.textBoxExtra.Size = new System.Drawing.Size(100, 20);
            this.textBoxExtra.TabIndex = 0;
            // 
            // buttonExtra
            // 
            this.buttonExtra.Location = new System.Drawing.Point(56, 87);
            this.buttonExtra.Name = "buttonExtra";
            this.buttonExtra.Size = new System.Drawing.Size(75, 23);
            this.buttonExtra.TabIndex = 1;
            this.buttonExtra.Text = "Add";
            this.buttonExtra.UseVisualStyleBackColor = true;
            this.buttonExtra.Click += new System.EventHandler(this.buttonCloseForm2_Click);
            // 
            // labelBook
            // 
            this.labelBook.AutoSize = true;
            this.labelBook.Location = new System.Drawing.Point(31, 9);
            this.labelBook.Name = "labelBook";
            this.labelBook.Size = new System.Drawing.Size(117, 13);
            this.labelBook.TabIndex = 2;
            this.labelBook.Text = "Type in author for book";
            // 
            // labelMovie
            // 
            this.labelMovie.AutoSize = true;
            this.labelMovie.Location = new System.Drawing.Point(69, 22);
            this.labelMovie.Name = "labelMovie";
            this.labelMovie.Size = new System.Drawing.Size(88, 13);
            this.labelMovie.TabIndex = 3;
            this.labelMovie.Text = "director for movie";
            // 
            // labelCD
            // 
            this.labelCD.AutoSize = true;
            this.labelCD.Location = new System.Drawing.Point(69, 35);
            this.labelCD.Name = "labelCD";
            this.labelCD.Size = new System.Drawing.Size(62, 13);
            this.labelCD.TabIndex = 4;
            this.labelCD.Text = "artist for CD";
            // 
            // Form2
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(193, 134);
            this.Controls.Add(this.labelCD);
            this.Controls.Add(this.labelMovie);
            this.Controls.Add(this.labelBook);
            this.Controls.Add(this.buttonExtra);
            this.Controls.Add(this.textBoxExtra);
            this.Name = "Form2";
            this.Text = "Form2";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxExtra;
        private System.Windows.Forms.Button buttonExtra;
        private System.Windows.Forms.Label labelBook;
        private System.Windows.Forms.Label labelMovie;
        private System.Windows.Forms.Label labelCD;
    }
}