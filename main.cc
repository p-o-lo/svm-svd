#include<iostream>
#include <sys/stat.h>
#include"inputData.h"
#include"coordinates.h"
#include"basis.h"
#include"print_tuple.h"

int
main(int argc, char ** argv)
{
  if(argc!=2)
  {
    std::cerr << "Usage:\n" << argv[0]<< " <input_file> " << std::endl;
    exit(-1);
  }

  std::string inputFile = argv[1];
  InputData inData(inputFile) ;

  std::string baseName = inData.dataFile;
  
  std::string inputName = baseName + ".input";
  std::string alphN = "alphas_for_reinfor";
  std::string sigmN = "sigmas_for_reinforc";
  std::string alphasName;
  std::string sigmasName;
  struct stat buffer;
  int i=0;
  while(stat(inputName.c_str(), &buffer) == 0)
  {
    baseName = inData.dataFile + "_" + std::to_string(i);
    inputName = baseName + ".input";
    alphasName = alphN + "_" + std::to_string(i);
    sigmasName = sigmN + "_" + std::to_string(i);
    i++;
  } 




  ofstream file(inputName.c_str()); 
  //InputData inStd ;
  //std::cout << inStd << std::endl;
  file << inData << std::endl;
  file.close();

  file.open(baseName+".output");
  std::cout << "Writing on " << baseName+ ".output" << std::endl;
  ofstream fileA(alphasName+".dat");
  ofstream fileS(sigmasName+".dat");

 
  /*
   * Set up of the matrices 
   * to move from Jacobi to/from cartesian
   */

  Coordinates cc(inData.npart,inData.masses,inData.totalSpin,inData.totalIsospin,inData.ifCoulomb);

  /*
   * Just for debug
   */
  /* 
  for(auto v : cc.primitiveS)
  {
    for(auto e : v)
      std::cout << e << "   " ;
    std::cout << std::endl;
  }
  std::cout << " ----------------------- "  << std::endl;
  
  for(auto t : cc.traspositionSpin)
    std::cout << t << std::endl << " ---- " << std::endl;

  std::cout << "************************" << std::endl;
  for(auto i : cc.irrepsS)
  {
    for(auto e : i)
      std::cout << e << "  " ;
    std::cout << std::endl;
  }
  std::cout << "************************" << std::endl;

  std::cout << cc.lS << std::endl;
  std::cout << "++++++++++++++++++++++++" << std::endl;



 
  std::cout << "Base primitiva di isospin nella notazione 12" << std::endl;
  for(auto v : cc.primitiveS)
  {
    for(auto e : v)
      std::cout << e << "   " ;
    std::cout << std::endl;
  }
  std::cout << " ----------------------- "  << std::endl;



  std::cout << "Scambio nella base primitiva" << std::endl;
  for(auto t : cc.traspositionIsospin)
    std::cout << t << std::endl << " ---- " << std::endl;

  std::cout << "************************" << std::endl;



  std::cout << "\t\t Rappresentazione irriducibili spin nella notazione 12" << std::endl;
  std::cout << "Rappresentazione di Dimensione " << cc.irrepsS.size() << std::endl;
  for(auto i : cc.irrepsS)
  {
    for(auto e : i)
      std::cout << e << "  " ;
    std::cout << std::endl;
  }
  std::cout << "Coefficient Rappresentazioni irriducibili " << std::endl;
  std::cout << "************************" << std::endl;
    std::cout << "\t Coefficienti della Rappresentazione di Dimensione " << cc.lS.rows() << std::endl;
    std::cout << "\t Over the primitive basis of dimension " << cc.lS.cols() << std::endl;
    std::cout << cc.lS << std::endl;
 
  std::cout << "++++++++++++++++++++++++" << std::endl;



  std::cout << "\t\t Rappresentazioni irriducibili isospin nella notazione 12" << std::endl;
  for(auto ir : cc.irrepsI)
  {
    std::cout << "Rappresentazione di Dimensione " << ir.size() << std::endl;
    for(auto i : ir)
    {
      for(auto e : i)
        std::cout << e << "  " ;
      std::cout << std::endl;
    }
  }
  std::cout << "Coefficient Rappresentazioni irriducibili " << std::endl;
  std::cout << "************************" << std::endl;
  for(auto cir : cc.lI)
  {
    std::cout << "\t Coefficienti della Rappresentazione di Dimensione " << cir.rows() << std::endl;
    std::cout << cir << std::endl;
  }
  std::cout << "++++++++++++++++++++++++" << std::endl;


  
  std::cout << cc.projectorIsospin.size() << std::endl;
  std::cout << cc.projectorIsospin[0].first << std::endl;
  std::cout << cc.projectorIsospin[0].second<< std::endl;

  for(auto q : cc.chargeOperator)
    std::cout << q << std::endl << "--- " << std::endl;
  abort();

  abort();
  */
  /*
  for(size_t i=0; i<cc.pairs.size(); i++)
    std::cout << cc.pairs[i].first << " " << cc.pairs[i].second << std::endl;
  std::cout << std::endl;
  for(size_t i=0; i<cc.triplets.size(); i++)
    std::cout << std::get<0>(cc.triplets[i]) << " " << std::get<1>(cc.triplets[i]) << " " << std::get<2>(cc.triplets[i]) << std::endl;
  for(auto q : cc.quadruplets)
		std::cout << q << std::endl;
 

  std::cout << "************ U ***********\n" << std::endl;
  std::cout << cc.U << std::endl;
  std::cout << "************ U INV ************\n" << std::endl;
  std::cout << cc.UINV << std::endl;
  std::cout << "************ U*UINV (SHOULD BE UNITARY) ***********\n" << std::endl;
  std::cout << cc.U * cc.UINV << std::endl;
  std::cout << "************ Omega Matrix ?? ***********\n" << std::endl;
  std::cout << cc.Omega << std::endl;
  std::cout << "************ Lambda Matrix (for Kinetic energy) ***********\n" << std::endl;
  std::cout << cc.Lambda << std::endl;
  std::cout << "************ Lambda*Omega ***********\n" << std::endl;
  std::cout << cc.Lambda*cc.Omega << std::endl;
//  abort(); 
  std::cout << "--- Jacobi Perm" << std::endl;
  for(auto p : cc.permutationsJacobi)
  {
    std::cout << p << std:: endl;
    std::cout << "---" << std::endl;
  }

//  abort();

 
 // std::cout << cc.U << std::endl;
  std::cout << "--- Perm " << std::endl; 
  std::cout << cc.permutations[1].toDenseMatrix() << std::endl;
  std::cout << "--- Perm*U" << std::endl;
  std::cout << cc.permutations[1]*cc.U << std::endl;
  std::cout << "--- T^anspositions" << std::endl;
  for(auto i=cc.transpositions.begin(); i<cc.transpositions.end(); i++)
    std::cout << i->toDenseMatrix() << std::endl << std::endl;
  std::cout << "--- U Inv" << std::endl;
  std::cout << cc.UINV << std::endl;
   std::cout << "--- Identity" << std::endl;
 std::cout << cc.U * cc.UINV << std::endl;
   std::cout << "--- Lambda" << std::endl;
 std::cout << cc.Lambda << std::endl;
  std::cout << "*********KIN********"<< std::endl;

  std::cout << cc.KIN << std::endl;
   std::cout << "--- V Inv" << std::endl;
 std::cout << cc.VINV << std::endl;

 */
   
  /*std::cout << "*****************"<< std::endl;
  std::cout << cc.W << std::endl;
  std::cout << "*****************"<< std::endl;
//  abort();
  std::cout << cc.WV << std::endl;
  std::cout << "*****************"<< std::endl;
  std::cout << cc.Z << std::endl;
  std::cout << "*****************"<< std::endl;
  Eigen::MatrixXd A = cc.Z*cc.W.transpose()/2;
  std::cout << A << std::endl;
  std::cout << A.rowwise().sum() << std::endl;

*/


  Basis base(inData,cc);

  //base.printCouplings(std::cout);


  int noflevels = inData.alphaRanges[0].size()/2;


  int nOfProve = 1;
  int nOfcicles =0;
  int startPoint=0;

  for(int l=0; l<noflevels; l++)
  {
    base.setState(l);
    double precision =1;
    double oldEnergy = 1;
    do {
          auto output = base.testElement();
	    
	    //std::cout << "First random matrix A:"<<std::endl;
//	   std::cout << std::get<1>(output).first.transpose() << std::endl;
          for(auto j=0; j< nOfProve; j++)
          {
            auto tmpOut = base.testElement();
            /*Eigen::MatrixXd overlaps = base.getGIJ()->block(0,0,base.getDimension()+1,base.getDimension()+1);
	    Eigen::MatrixXd hamil = base.getHAIJ()->block(0,0,base.getDimension()+1,base.getDimension()+1) + base.getVAIJ()->block(0,0,base.getDimension()+1,base.getDimension()+1);
	    Eigen::MatrixXd eigenvals = *base.getEnergy();*/
     
	    /*std::cout << "*************" << std::endl;     
            std::cout << "The overlaps at dimension " <<base.getDimension() << " is \n" << overlaps << std::endl;
            std::cout << "*************" << std::endl;
	    std::cout << "The hamil matrix at this stage is \n " << hamil << std::endl;
            std::cout << "*************" << std::endl;*/
	   /* if(overlaps.determinant() < 1e-3) {
		std::cout << "The random alphas at dimension " << base.getDimension() << " are parallel to a previous one" << std::endl;
	        std::cout << "*************" << std::endl;
                std::cout << "The overlap matrix at this stage is \n " << overlaps << std::endl;
                std::cout << "*************" << std::endl;
		std::cout << "The overlap vector tested at this stage is \n " << overlaps.col(base.getDimension()-1) << std::endl;
                std::cout << "*************" << std::endl;
		std::cout << "The determinant of the overlaps at this stage is " << overlaps.determinant() << std::endl;
		std::cout << "The hamil matrix at this stage is \n " << hamil << std::endl;
                std::cout << "*************" << std::endl;

		std::cout << "The Energy is " << std::get<0>(tmpOut)(l) << std:: endl;
		std::cerr << "CONTINUE" << std::endl;
		continue;
	    }*/

            
	    if(base.getPrincipalDimension() != base.getDimension()){
		    std::cout << "Maybe NaN" <<  std::endl;
		    std::cout <<" The full dim is " << base.getDimension() << "  The principal dim is " << base.getPrincipalDimension() << std::endl;
	    }

	    /*
	    if(std::get<0>(tmpOut)(l) != std::get<0>(tmpOut)(l))
            {
	      std::cout << "NaN comes at dimesnion: " << base.getDimension() << std::endl;	   
	      std::cout << "*************" << std::endl;
	      std::cout << "The overlap matrix at this stage is \n " << overlaps << std::endl;
	      std::cout << "*************" << std::endl;
	      std::cout << "The overlap vector tested at this stage is \n " << overlaps.col(base.getDimension()-1) << std::endl;
              std::cout << "*************" << std::endl;
	      std::cout << "The determinant of the overlaps at this stage is " << overlaps.determinant() << std::endl;
	      std::cout << "The hamil matrix at this stage is \n " << hamil << std::endl;
              std::cout << "*************" << std::endl;

	      std::cout << "The Energy is " << std::get<0>(tmpOut)(l) << std:: endl;
              std::cerr << "CONTINUE" << std::endl;
	      
              continue;
            }*/

	  if(std::get<0>(tmpOut)(l) < std::get<0>(output)(l))
              output = tmpOut;
        
 	}
	  /*
          if(std::get<0>(output)(l) != std::get<0>(output)(l)) {
	      //std::cout << "NaN comes at dimesnion: " << base.getDimension() << std::endl;	    
              //std::cerr << "CONTINUE" << std::endl;
	      continue;
	  }*/
 
	  Eigen::MatrixXd e = *base.getEnergy();
          double newEnergy = e(l,0);

	  /*std::cout << "The eigenvals at this stage is TestEl \n " << e.block(0,0,base.getDimension()+1,1) << std::endl;
          std::cout << "*************" << std::endl;*/
       
	  base.newElement(std::get<1>(output),std::get<2>(output),std::get<3>(output),std::get<4>(output));  

	std::cout <<" The full dim is " << base.getDimension() << "  The principal dim is " << base.getPrincipalDimension() << std::endl;

          // file << inData.energyUnits*newEnergy << "  " << nOfcicles << std::endl;
          e = *base.getEnergy();
          newEnergy = e(l,0);

	  /*std::cout << "The eigenvals at this stage is newEl \n " << e.block(0,0,base.getDimension()+1,1) << std::endl;
          std::cout << "*************" << std::endl;*/

          precision = fabs(oldEnergy-newEnergy)/fabs(oldEnergy);

          oldEnergy = newEnergy;
          nOfcicles++;
          /*
          if(!(nOfcicles%50)&&nOfcicles<150)
          {
            file << "Refining" << std::endl;
            base.refineSimplex(startPoint);
            startPoint=nOfcicles;
              
            //for(int i=0;i<1;i++)
              //base.refineBasis(10);
          }
          */
	
	
  Eigen::MatrixXd c = base.getCIJ()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd cas = base.getCasimir()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd casSpace = base.getCasimirSpace()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd casSpin = base.getCasimirSpin()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd casIso = base.getCasimirIso()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd casSpinIso = base.getCasimirSpinIso()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd z = c.transpose()*cas*c ;
  Eigen::MatrixXd zSpace = c.transpose()*casSpace*c ;
  Eigen::MatrixXd zSpin = c.transpose()*casSpin*c ;
  Eigen::MatrixXd zIso = c.transpose()*casIso*c ;
  Eigen::MatrixXd zSpinIso = c.transpose()*casSpinIso*c ;
  Eigen::MatrixXd g = base.getGIJ()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::VectorXd alp = std::get<2>(output);

  //file << inData.energyUnits*newEnergy << "  " << nOfcicles ;
  double scale=0.;
  
  /*
  file <<  std::endl << "Energies   " << std::endl ;
  for(auto i=0; i<7; i++)
    file <<  inData.energyUnits*e(i,0)-scale*z.diagonal()[i]  << "   " ;
  file << nOfcicles <<  "  stato = " << l << std::endl;
  */


  file << nOfcicles  << "\t" << inData.energyUnits*e(0,0) << '\t' << base.getDimension() << '\t' << base.getPrincipalDimension() << std::endl;

  fileA << std::setprecision(18) <<  alp(0) << " " << alp(1) << " " << alp(2) << std::endl;
  fileS << std::setprecision(18) << sqrt(1/alp(0)) << " " << sqrt(1/alp(1)) << " " << sqrt(1/alp(2)) << std::endl;


  /*
  //file << "\t \t Casimir  "  << z.diagonal()[l] << "   " << -scale*z.diagonal()[l] + inData.energyUnits*newEnergy << std::endl;
  file << "\t \t Casimir  \n" << std::endl << z.block(0,0,4,4) << std::endl;
  file << "\t \t Casimir Spacial \n" << std::endl << zSpace.block(0,0,4,4) << std::endl;
  file << "\t \t Casimir Spin \n" << std::endl << zSpin.block(0,0,4,4) << std::endl;
  file << "\t \t Casimir IsoSpin \n" << std::endl << zIso.block(0,0,4,4) << std::endl;
  file << "\t \t Casimir Spin and IsoSpin \n" << std::endl << zSpinIso.block(0,0,4,4) << std::endl;

  */
  /*
  if (nOfcicles == 10)
  {
    std::cerr << "Hamiltoniana nella base non ortonormale" << std::endl;
    std::cerr << t+q+v+v3 << std::endl;
    std::cerr << "Casimiro nella base non ortonormale" << std::endl;
    std::cerr << cas << std::endl;
    std::cerr << "Matrice della norma " << std::endl;
    std::cerr << g << std::endl;
    std::cerr << "Matrice di diagonalizzazione" << std::endl;
    std::cerr << c << std::endl;
    abort();
  }
  */

  /*
     if(l<4 && nOfcicles>20)
       break;
   */

    //} while(nOfcicles < inData.sizeBasis);
    } while (nOfcicles < inData.sizeBasis);
  // precision > 1e-12);
  //(( l == 0  && nOfcicles < 100 && precision > 1e-9) || (l == 1 && nOfcicles < inData.sizeBasis && precision > 1e-9) );
    // file << nOfcicles <<"  precision " <<precision << std::endl;
   //base.refineSimplex(5);
   //nOfcicles=0;
  }




  /*
   * Just for debug
   */
  /*
  for(auto a : base.A)
  {
    file << "*****************"<< std::endl;
    file << a << std::endl;
    file << "*****************"<< std::endl;
  }

  file << "****** GIJ ***********"<< std::endl;
  file << base.getGIJ()->block(0,0,base.getDimension(),base.getDimension()) << std::endl;
  file << "*****************"<< std::endl;
  file << base.getHAIJ()->block(0,0,base.getDimension(),base.getDimension())  << std::endl;
  file << "*****************"<< std::endl;
  file << base.getVAIJ()->block(0,0,base.getDimension(),base.getDimension())  << std::endl;
  file << "*****************"<< std::endl;
  file << base.getPHIIJ()->block(0,0,base.getDimension(),base.getDimension())  << std::endl;
  file << "*****************"<< std::endl;
  */

  Eigen::MatrixXd g = base.getGIJ()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd r2 = base.getRAIJ()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd cas = base.getCasimir()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd c = base.getCIJ()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd t = base.getHAIJ()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd v = base.getVAIJ()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd v3 = base.getTAIJ()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::MatrixXd u = base.getUIJ()->block(0,0,base.getDimension(),base.getPrincipalDimension());

  Eigen::MatrixXd e = *base.getEnergy();
  Eigen::MatrixXd z = c.transpose()*cas*c ;
  
  /*Eigen::MatrixXd z = cas*u; 
  Eigen::BDCSVD<Eigen::MatrixXd> svdCas(z);
  
  Eigen::MatrixXd tmp = r2*u;
  Eigen::BDCSVD<Eigen::MatrixXd> svdR2(tmp);*/
  
  /*file.open("test.txt"); 
  file << c.transpose()*g*c << std::endl;
  file << c << std::endl;
  file << g << std::endl;
  file.close();
  */


  /*
  for (int l=0; l<noflevels; l++)
  {
      file << "The energy of the " << l <<"-state = " << inData.energyUnits*e(l,0) << std::endl;
      file << "Casimir of the " << l <<"-state = "  << z.diagonal()[l] << std::endl << std::endl;
      //file << "Casimir of the " << l <<"-state = "  << svdCas.singularValues()(base.getPrincipalDimension()-l) << std::endl << std::endl;

      Eigen::MatrixXd tmp = c.transpose()*r2*c;
      file << "The (<r^2>)^1/2  is " << sqrt(inData.lengthUnits*tmp(l,l)) << std::endl;
      //file << "The (<r^2>)^1/2  is " << sqrt(inData.lengthUnits*svdR2.singularValues()(base.getPrincipalDimension()-l)) << std::endl;

  }

  */

      //std::cout << inData.energyUnits*e(1,0) << std::endl;
      //std::cout << inData.energyUnits*e(0,0) << std::endl;
  /*
  Eigen::MatrixXd h = inData.energyUnits * c.transpose()*(t+v+v3)*c ;
  file << h << std::endl << std::endl;
  */

  // and set the new cij_ of the reduced basis
 /*
  Eigen::GeneralizedSelfAdjointEigenSolver <Eigen::MatrixXd> 
     es(cas,g);
 
  std::cerr << es.eigenvalues() << std::endl;

  Eigen::MatrixXd casSpace = base.getCasimirSpace()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::GeneralizedSelfAdjointEigenSolver <Eigen::MatrixXd> 
     esSpace(casSpace,g);
  std::cerr << "# Spaziale" << std::endl<< std::endl;
  std::cerr << esSpace.eigenvalues() << std::endl;

  Eigen::MatrixXd casSpinIso = base.getCasimirSpinIso()->block(0,0,base.getDimension(),base.getDimension());
  Eigen::GeneralizedSelfAdjointEigenSolver <Eigen::MatrixXd> 
     esSpinIso(casSpinIso,g);
  std::cerr << "# SpinIso" << std::endl<< std::endl;
  std::cerr << esSpinIso.eigenvalues() << std::endl;
 */

  fileA.close();
  fileS.close();
  file.close();
  base.saveAll(baseName + ".h5");
  return 0;
}
