// Copyright (c) 2012, National ICT Australia
// All rights reserved.
//
// The contents of this file are subject to the Mozilla Public License
// Version 2.0 (the "License"); you may not use this file except in
// compliance with the License. You may obtain a copy of the License at
// http://www.mozilla.org/MPL/
//
// Software distributed under the License is distributed on an "AS IS"
// basis, WITHOUT WARRANTY OF ANY KIND, either express or implied. See the
// License for the specific language governing rights and limitations
// under the License.
#ifndef __Gppe_H__
#define __Gppe_H__
#include <Eigen/Dense>
#include <Eigen/Sparse>
#include <iostream>
#include <string>
#include "Covfunc.h"
using namespace std;
using Eigen::VectorXd;
using Eigen::MatrixXd;
using Eigen::SparseMatrix;


class Gppe
{
	public :
	Gppe();// Default Contructor
	Gppe(VectorXd fnew,MatrixXd Kxnew,MatrixXd Kinvnew,MatrixXd Wnew,MatrixXd Lnew); //Constructor with parameters
	Gppe(const Gppe & g); //Contructor by recopy
	~Gppe(); // Destructor
	VectorXd Getf();
	MatrixXd GetKx();
	MatrixXd GetKinv();
	MatrixXd GetW();
	MatrixXd GetL();




	//void Predict_Gppe_Laplace();
	//void Get_Predictive_Utility();
	void Approx_Gppe_Laplace(Covfunc *covfunc_t,Covfunc *covfunc_x,
    VectorXd theta_x,VectorXd theta_t,double sigma,MatrixXd t,MatrixXd x,TypePair all_pairs,VectorXd idx_global,VectorXd idx_global_1,VectorXd idx_global_2, VectorXd ind_t,VectorXd ind_x,int M,int N);
	double log_likelihood(VectorXd f,double sigma, TypePair all_pairs,VectorXd idx_global_1,VectorXd idx_global_2,int N);
	VectorXd deriv_log_likelihood_gppe_fast(VectorXd f,double sigma, TypePair all_pairs, VectorXd idx_global_1, VectorXd idx_global_2,int M, int N);
	MatrixXd deriv2_log_likelihood_gppe_fast(VectorXd f,double sigma, TypePair all_pairs, VectorXd idx_global_1, VectorXd idx_global_2,int M, int N);

	//void Prediction_New_User();
	//Variables
	private :
		VectorXd f;
	 	MatrixXd Kx;
	 	MatrixXd Kinv;
	 	MatrixXd W;
	 	MatrixXd L;
	 	Covfunc *covfunc_x;
	 	Covfunc *covfunc_t;
};
#endif