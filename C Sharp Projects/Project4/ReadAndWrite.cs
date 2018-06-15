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
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Project4{
    class ReadAndWrite{

        //BindingList<Record> record = new BindingList<Record>();
        public void WriteFile(BindingList<Record> record){
            using (StreamWriter writer = new StreamWriter(@"file.txt")){
                foreach (Record rec in record){
                    writer.WriteLine(rec.title + "|" + rec.year + "|" + rec.type);
                }
            }
        }
        public void ReadFile(BindingList<Record> record){
            // If the file doesn't exist, create it
            if (!File.Exists(@"file.txt")){
                File.Create(@"file.txt");
                return; // Since no file existed, nothing in the file to read, exit the method
            }

            using (StreamReader reader = new StreamReader(@"file.txt")){
                string line = reader.ReadLine();

                // If the line isn't blank, do something with it
                while (line != null){
                    string[] parts = line.Split('|'); // Split the line up using the delimeter we wrote with
                    Record readRecord = new Record();
                    readRecord.title = parts[0]; // We know from the WriteFile method the order of the parts
                    readRecord.year = parts[1];
                    readRecord.type = parts[2];
                    record.Add(readRecord);
                    line = reader.ReadLine();
                }
            }
        }
    }
}
