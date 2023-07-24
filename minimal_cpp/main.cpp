#include <iostream>
#include <string>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include "../util/Util.h"
#include "../io/IO.h"
#include "../graph/Graph.h"
#include "../match/Match.h"
#include <pybind11/pybind11.h>

namespace py = pybind11;

using namespace std;

//NOTICE:a pattern occurs in a graph, then support++(not the matching num in a graph), support/N >= minsup
// class IO {
// public:
//     IO() {
//         this->qfp = NULL;
//         this->dfp = NULL;
//         this->ofp = NULL;
//         this->data_id = -1;
//     }

//     IO(std::string query, std::string data, std::string file)
//     {
//         this->data_id = -1;
//         this->line = "============================================================";
//         qfp = fopen(query.c_str(), "r");
//         if (qfp == NULL) {
//             cerr << "input open error!" << endl;
//             return;
//         }
//         dfp = fopen(data.c_str(), "r");
//         if (dfp == NULL) {
//             cerr << "input open error!" << endl;
//             return;
//         }
//         ofp = fopen(file.c_str(), "w+");
//         if (ofp == NULL) {
//             cerr << "output open error!" << endl;
//             return;
//         }
//     }

//     void flush() {
//         fflush(this->ofp);
//     }

// private:
// 	std::string line;
// 	int data_id;
// 	//query file pointer       
// 	FILE* qfp;
// 	//data file pointer
// 	FILE* dfp;
// 	//output file pointer
// 	FILE* ofp;
// };

int
run(std::string query, std::string data, std::string file)
{
	int i;
	string output = file;
    // cout << query<< data << file << endl;
	IO io = IO(query, data, output);
    io.flush();
    cout << "worked!" << endl;
	return 0;
}

PYBIND11_MODULE(main, m) {
    m.doc() = "pybind11 example plugin"; // optional module docstring

    m.def("run", &run, "A function that reads files");
}