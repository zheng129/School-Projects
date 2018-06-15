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
    public partial class Form1 : Form{
        BindingList<Record> record = new BindingList<Record>();
        ReadAndWrite rnw = new ReadAndWrite();

        public static Form1 form1;

        Form2 form2;

        public Form1(){
            InitializeComponent();
            form1 = this;
            form2 = new Form2(form1);
            rnw.ReadFile(record);
            BindListBox();
        }

        private void BindListBox(){
            listBoxTitle.DataSource = record;
            listBoxTitle.DisplayMember = "displayTitle";
        }

        private void btnSaveRecord_Click(object sender, EventArgs e){

            if ((txtType.Text.ToLower()) == "book"){
                string author = labelExtra.Text;
                this.form2.ShowDialog();
                record.Add(new Record() {
                    title = txtTitle.Text,
                    year = txtYear.Text,
                    type = new Book(author)
                });
            }

            else if ((txtType.Text.ToLower()) == "movie"){
                string director = labelExtra.Text;
                this.form2.ShowDialog();
                record.Add(new Record(){
                    title = txtTitle.Text,
                    year = txtYear.Text,
                    type = new Movie(director)
                });
            }

            else if ((txtType.Text.ToLower()) == "cd"){
                string artist = labelExtra.Text;
                this.form2.ShowDialog();
                record.Add(new Record(){
                    title = txtTitle.Text,
                    year = txtYear.Text,
                    type = new CD(artist)
                });
            }

            else{
                record.Add(new Record(){
                    title = txtTitle.Text,
                    year = txtYear.Text,
                    type = new Record()
                });
            }

            rnw.WriteFile(record);

            // If adding the first account, auto-select it
            if (record.Count == 1){
                listBoxTitle.SelectedIndex = 0;
                listBoxTitle_SelectedIndexChanged(sender, e);
                listBoxTitle.Update();
            }
        }

        private void listBoxTitle_SelectedIndexChanged(object sender, EventArgs e){
            if (listBoxTitle.SelectedIndex > -1){
                lblRecord.Text = record[listBoxTitle.SelectedIndex].displayRecord;
                if ((txtType.Text.ToLower()) == "book"){
                    lblType.Text = record[listBoxTitle.SelectedIndex].displayRecord; // cannot figure it out
                }
                else if ((txtType.Text.ToLower()) == "movie"){
                    lblType.Text = record[listBoxTitle.SelectedIndex].displayRecord; // same
                }
                else if ((txtType.Text.ToLower()) == "cd"){
                    lblType.Text = record[listBoxTitle.SelectedIndex].displayRecord; // same
                }
            }
        }

        private void btnDeleteRecord_Click(object sender, EventArgs e){
            if (listBoxTitle.SelectedIndex > -1){
                record.RemoveAt(listBoxTitle.SelectedIndex);
                rnw.WriteFile(record);
            }
        }

        private void txtTitle_Enter(object sender, EventArgs e){
            txtTitle.SelectAll();
        }

        private void txtYear_Enter(object sender, EventArgs e){
            txtYear.SelectAll();
        }

        private void txtType_Enter(object sender, EventArgs e){
            txtType.SelectAll();
        }
    }
}

