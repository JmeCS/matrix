#include <random>
#include <algorithm>
#include <iostream>


int getRandom() {
  return rand() % 99;
}

std::vector<double> fillVectorRandom(int n, int seed = 0) {
  srand(seed);
  std::vector<double> out(n, 0.0);
  std::generate(out.begin(), out.end(), getRandom);
  return(out);
}

std::vector<double> fillVectorUnif(int n, double lower_bound, double upper_bound) {
  std::vector<double> out;

  std::random_device rd;
  std::mt19937_64 generator{rd()};
  std::uniform_real_distribution<> dist{lower_bound, upper_bound};

  for (int i = 0; i < n; i++) {
    out.push_back(dist(generator));
  }

  return(out);
}


int main(int argc, char const *argv[]) {

  double lower_bound = 0;
  double upper_bound = 10000;
  std::uniform_real_distribution<double> unif(lower_bound, upper_bound);
  std::default_random_engine re;
  double a_random_double = unif(re);

  std::cout << a_random_double << std::endl;

  std::vector<double> v1 = fillVectorRandom(10);
  for (int i = 0; i < 10; i++) {
    std::cout << v1[i] << std::endl;
  }

  std::vector<double> v2 = fillVectorRandom(10, 99);
  for (int i = 0; i < 10; i++) {
    std::cout << v2[i] << std::endl;
  }

  std::cout << " " << std::endl;

  std::vector<double> v3 = fillVectorUnif(5, 0, 1000);
  for (int i = 0; i < v3.size(); i++) {
    std::cout << v3[i] << std::endl;
  }


  std::cout << " " << std::endl;

  std::vector<double> v4 = fillVectorUnif(8, 0, 1000);
  for (int i = 0; i < v4.size(); i++) {
    std::cout << v4[i] << std::endl;
  }


  return 0;
}
