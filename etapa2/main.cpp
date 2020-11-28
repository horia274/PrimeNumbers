#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>

#include "algo1.h"
#include "algo2.h"

using namespace std;
using namespace std::chrono;

void create_paths_fermat(int no_test, string &path_input, string &path_output, string &path_ref) {
    path_input = "./in/test";
    path_input += std::to_string(no_test);
    path_input += ".in";

    path_output = "./out/out1/test";
    path_output += std::to_string(no_test);
    path_output += ".out";

    path_ref = "./ref/test";
    path_ref += std::to_string(no_test);
    path_ref += ".ref";
}

void create_paths_miller_rabin(int no_test, string &path_input, string &path_output, string &path_ref) {
    path_input = "./in/test";
    path_input += std::to_string(no_test);
    path_input += ".in";

    path_output = "./out/out2/test";
    path_output += std::to_string(no_test);
    path_output += ".out";

    path_ref = "./ref/test";
    path_ref += std::to_string(no_test);
    path_ref += ".ref";
}

vector<int> read_input(string path_input) {
    int n, tmp;
    ifstream fin;

    fin.open(path_input);
    fin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        fin >> tmp;
        v.push_back(tmp);
    }
    fin.close();
    return v;
}

void write_output_fermat(string path_output1, vector<int> v) {
    vector<int> primes = filter_non_prime_fermat(v);
    vector<int>::iterator prime;
    ofstream fout;

    fout.open(path_output1);
    fout << primes.size() << "\n";
    // cout << primes.size() << "\n";
    for (prime = primes.begin(); prime < primes.end(); prime++) {
        fout << *prime << " ";
    }
    fout.close();
}

void write_output_miller_rabin(string path_output2, vector<int> v) {
    vector<int> primes = filter_non_prime_miller_rabin(v);
    vector<int>::iterator prime;
    ofstream fout;

    fout.open(path_output2);
    fout << primes.size() << "\n";
    // cout << primes.size() << "\n";
    for (prime = primes.begin(); prime < primes.end(); prime++) {
        fout << *prime << " ";
    }
    fout.close();
}

bool checker(string path_output, string path_ref) {
    int size_out, size_ref;
    int tmp_out, tmp_ref;
    ifstream fout, fref;
    
    fout.open(path_output);
    fref.open(path_ref);

    fout >> size_out;
    fref >> size_ref;

    if (size_out != size_ref) {
        return false;
    }

    for (int i = 0; i < size_out; i++) {
        fout >> tmp_out;
        fref >> tmp_ref;
        if (tmp_out != tmp_ref) {
            return false;
        }
    }

    return true;
}

void check_test_fermat(int no_test, int &count_correct_tests) {
    string path_input, path_output, path_ref;
    vector<int> v;

    auto start = high_resolution_clock::now();

    create_paths_fermat(no_test, path_input, path_output, path_ref);
    v = read_input(path_input);
    write_output_fermat(path_output, v);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if(checker(path_output, path_ref)) {
        count_correct_tests++;
        cout << "test" <<  no_test << "\t\t\t\t\t\t\tPASSED [5/5]\n";
        cout << "time taken" << "\t\t\t\t\t\t" << duration.count() << " micro\n";
    } else {
        cout << "test" <<  no_test << "\t\t\t\t\t\t\tFAILED [0/5]\n";
        cout << "time taken" << "\t\t\t\t\t\t" << 0 << " micro\n";
    }
}

void check_test_miller_rabin(int no_test, int &count_correct_tests) {
    string path_input, path_output, path_ref;
    vector<int> v;

    auto start = high_resolution_clock::now();

    create_paths_miller_rabin(no_test, path_input, path_output, path_ref);
    v = read_input(path_input);
    write_output_miller_rabin(path_output, v);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    if(checker(path_output, path_ref)) {
        count_correct_tests++;
        cout << "test" <<  no_test << "\t\t\t\t\t\t\tPASSED [5/5]\n";
        cout << "time taken" << "\t\t\t\t\t\t" << duration.count() << " micro\n";
    } else {
        cout << "test" <<  no_test << "\t\t\t\t\t\t\tFAILED [0/5]\n";
        cout << "time taken" << "\t\t\t\t\t\t" << 0 << " micro\n";
    }
}

int main() {
    int count_correct_fermat = 0;
    int count_correct_miller_rabin = 0;

    cout << "--------------------------------------------------------------------\n";
    cout << "--------------------- TEMA AA - ETAPA 2 - 2020 ---------------------\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "------------------------------ FERMAT ------------------------------\n";

    for (int i = 0; i < 10; i++) {
        check_test_fermat(i, count_correct_fermat);
    }
    cout << "--------------------------------------------------------------------\n";
    cout << "FERMAT POINTS\t\t\t\t\t\t     [" << count_correct_fermat * 5 << "/50]\n";
    cout << "---------------------------- MILLER_RABIN --------------------------\n";

    for (int i = 0; i < 10; i++) {
        check_test_miller_rabin(i, count_correct_miller_rabin);
    }
    cout << "--------------------------------------------------------------------\n";
    cout << "MILLER RABIN POINTS\t\t\t\t\t     [" << count_correct_miller_rabin * 5 << "/50]\n";
    cout << "--------------------------------------------------------------------\n";
    cout << "TOTAL POINTS\t\t\t\t\t\t    [" << (count_correct_fermat + count_correct_miller_rabin) * 5 << "/100]\n";

    return 0;
}
