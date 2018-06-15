/*
 * Yixing Zheng
 * 2293298
 * zheng129@mail.chapman.edu
 * CPSC 236 - 03
 * Project 4
 */

using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.ComponentModel;

namespace Project4{
    class Record{
        public string title;
        public string year;
        public Object type;

        public string displayRecord { get { return "<" + title + ">, " + year; } }

        public override string ToString(){

            return title;
        }
    }

    class Book : Record{
        public string author { get; set; }
        public Book(string author){
            this.author = author;
        }
        public string displayBook { get { return "<" + title + ">, wrote by " + author + " ," + year; } }
    }

    class Movie : Record {
        public string director { get; set; }
        public Movie(string director){
            this.director = director;
        }
        public string displayMovie { get { return "<" + title + ">, directed by " + director + " ," + year; } }
    }

    class CD : Record {
        public string artist { get; set; }
        public CD(string artist){
            this.artist = artist;
        }
        public string displayCD { get { return "<" + title + ">, created by " + artist + " ," + year; } }
    }
}
