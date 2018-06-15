/*
 * Yixing Zheng
 * 2293298
 * zheng129@mail.chapman.edu
 * CPSC 236 - 03
 * Project 4
 */

namespace Project4
{
    partial class Form1
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
            this.title = new System.Windows.Forms.Label();
            this.txtTitle = new System.Windows.Forms.TextBox();
            this.year = new System.Windows.Forms.Label();
            this.txtYear = new System.Windows.Forms.TextBox();
            this.type = new System.Windows.Forms.Label();
            this.btnSaveRecord = new System.Windows.Forms.Button();
            this.lblRecord = new System.Windows.Forms.Label();
            this.lblType = new System.Windows.Forms.Label();
            this.btnDeleteRecord = new System.Windows.Forms.Button();
            this.txtType = new System.Windows.Forms.TextBox();
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.listBoxTitle = new System.Windows.Forms.ListBox();
            this.tabControl1 = new System.Windows.Forms.TabControl();
            this.labelExtra = new System.Windows.Forms.Label();
            this.tabPage1.SuspendLayout();
            this.tabControl1.SuspendLayout();
            this.SuspendLayout();
            // 
            // title
            // 
            this.title.AutoSize = true;
            this.title.Location = new System.Drawing.Point(12, 10);
            this.title.Name = "title";
            this.title.Size = new System.Drawing.Size(27, 13);
            this.title.TabIndex = 0;
            this.title.Text = "Title";
            // 
            // txtTitle
            // 
            this.txtTitle.Location = new System.Drawing.Point(15, 25);
            this.txtTitle.Name = "txtTitle";
            this.txtTitle.Size = new System.Drawing.Size(90, 20);
            this.txtTitle.TabIndex = 1;
            this.txtTitle.Enter += new System.EventHandler(this.txtTitle_Enter);
            // 
            // year
            // 
            this.year.AutoSize = true;
            this.year.Location = new System.Drawing.Point(12, 60);
            this.year.Name = "year";
            this.year.Size = new System.Drawing.Size(29, 13);
            this.year.TabIndex = 2;
            this.year.Text = "Year";
            // 
            // txtYear
            // 
            this.txtYear.Location = new System.Drawing.Point(15, 75);
            this.txtYear.Name = "txtYear";
            this.txtYear.Size = new System.Drawing.Size(90, 20);
            this.txtYear.TabIndex = 3;
            this.txtYear.Enter += new System.EventHandler(this.txtYear_Enter);
            // 
            // type
            // 
            this.type.AutoSize = true;
            this.type.Location = new System.Drawing.Point(12, 110);
            this.type.Name = "type";
            this.type.Size = new System.Drawing.Size(31, 13);
            this.type.TabIndex = 4;
            this.type.Text = "Type";
            // 
            // btnSaveRecord
            // 
            this.btnSaveRecord.Location = new System.Drawing.Point(15, 227);
            this.btnSaveRecord.Name = "btnSaveRecord";
            this.btnSaveRecord.Size = new System.Drawing.Size(100, 23);
            this.btnSaveRecord.TabIndex = 6;
            this.btnSaveRecord.Text = "Save Record";
            this.btnSaveRecord.UseVisualStyleBackColor = true;
            this.btnSaveRecord.TabStopChanged += new System.EventHandler(this.listBoxTitle_SelectedIndexChanged);
            this.btnSaveRecord.Click += new System.EventHandler(this.btnSaveRecord_Click);
            // 
            // lblRecord
            // 
            this.lblRecord.AutoSize = true;
            this.lblRecord.Location = new System.Drawing.Point(12, 150);
            this.lblRecord.Name = "lblRecord";
            this.lblRecord.Size = new System.Drawing.Size(0, 13);
            this.lblRecord.TabIndex = 8;
            // 
            // lblType
            // 
            this.lblType.AutoSize = true;
            this.lblType.Location = new System.Drawing.Point(12, 175);
            this.lblType.Name = "lblType";
            this.lblType.Size = new System.Drawing.Size(0, 13);
            this.lblType.TabIndex = 9;
            // 
            // btnDeleteRecord
            // 
            this.btnDeleteRecord.Location = new System.Drawing.Point(121, 227);
            this.btnDeleteRecord.Name = "btnDeleteRecord";
            this.btnDeleteRecord.Size = new System.Drawing.Size(100, 23);
            this.btnDeleteRecord.TabIndex = 8;
            this.btnDeleteRecord.Text = "Delete Record";
            this.btnDeleteRecord.UseVisualStyleBackColor = true;
            this.btnDeleteRecord.Click += new System.EventHandler(this.btnDeleteRecord_Click);
            // 
            // txtType
            // 
            this.txtType.Location = new System.Drawing.Point(15, 125);
            this.txtType.Name = "txtType";
            this.txtType.Size = new System.Drawing.Size(90, 20);
            this.txtType.TabIndex = 5;
            this.txtType.Enter += new System.EventHandler(this.txtType_Enter);
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.listBoxTitle);
            this.tabPage1.Location = new System.Drawing.Point(4, 22);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(142, 172);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "records";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // listBoxTitle
            // 
            this.listBoxTitle.FormattingEnabled = true;
            this.listBoxTitle.Location = new System.Drawing.Point(6, 5);
            this.listBoxTitle.Name = "listBoxTitle";
            this.listBoxTitle.Size = new System.Drawing.Size(130, 160);
            this.listBoxTitle.TabIndex = 7;
            this.listBoxTitle.SelectedIndexChanged += new System.EventHandler(this.listBoxTitle_SelectedIndexChanged);
            // 
            // tabControl1
            // 
            this.tabControl1.Controls.Add(this.tabPage1);
            this.tabControl1.Location = new System.Drawing.Point(121, 25);
            this.tabControl1.Name = "tabControl1";
            this.tabControl1.SelectedIndex = 0;
            this.tabControl1.Size = new System.Drawing.Size(150, 198);
            this.tabControl1.TabIndex = 11;
            // 
            // labelExtra
            // 
            this.labelExtra.AutoSize = true;
            this.labelExtra.Location = new System.Drawing.Point(186, 10);
            this.labelExtra.Name = "labelExtra";
            this.labelExtra.Size = new System.Drawing.Size(35, 13);
            this.labelExtra.TabIndex = 12;
            this.labelExtra.Text = "label1";
            this.labelExtra.Visible = false;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(284, 271);
            this.Controls.Add(this.labelExtra);
            this.Controls.Add(this.txtType);
            this.Controls.Add(this.tabControl1);
            this.Controls.Add(this.btnDeleteRecord);
            this.Controls.Add(this.lblType);
            this.Controls.Add(this.lblRecord);
            this.Controls.Add(this.btnSaveRecord);
            this.Controls.Add(this.type);
            this.Controls.Add(this.txtYear);
            this.Controls.Add(this.year);
            this.Controls.Add(this.txtTitle);
            this.Controls.Add(this.title);
            this.Name = "Form1";
            this.Text = "Records";
            this.tabPage1.ResumeLayout(false);
            this.tabControl1.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label title;
        private System.Windows.Forms.TextBox txtTitle;
        private System.Windows.Forms.Label year;
        private System.Windows.Forms.TextBox txtYear;
        private System.Windows.Forms.Label type;
        private System.Windows.Forms.Button btnSaveRecord;
        private System.Windows.Forms.Label lblRecord;
        private System.Windows.Forms.Label lblType;
        private System.Windows.Forms.Button btnDeleteRecord;
        private System.Windows.Forms.TextBox txtType;
        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.ListBox listBoxTitle;
        private System.Windows.Forms.TabControl tabControl1;
        public System.Windows.Forms.Label labelExtra;
    }
}

