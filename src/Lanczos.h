#ifndef LANCZOS_H_
#define LANCZOS_H_

#include "Sparse"
#include "Dense"

typedef Eigen::SparseMatrix<double> SpMat;
typedef Eigen::MatrixXd Mat;

class Lanczos {
public:
	Lanczos(SpMat& A, int k, Mat& V0, bool flag);
	bool validPairs(SpMat& A);

	Mat eigenValues() {
		return _eigenValues;
	}

	Mat eigenVectors() {
		return _eigenVectors;
	}
private:
	void computeEigenPairs(Mat& T, Mat& Q, int k);

	Mat _eigenValues;
	Mat _eigenVectors;
	double _theta;
	static const int max_iter = 100;
};


#endif /* LANCZOS_H_ */
