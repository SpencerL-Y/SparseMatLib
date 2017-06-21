# Sparse Matrix Library For Demonstration
- **Environment**: Win10 15063.296
- **Compiler**: g++ [-stl=c++11]
- **IDE**: Codeblocks 16.01
- **Status**: Under development

## Current members:
- Xie Li
- Yuan-Hang Zhang
- Yinan Xu


## Architecture

* MatLib
	* ArrayStore
		* Array1d: finished
		* Array2d: finished (with transpose)
	* CSRStore: Finished
	* ELLStore: Under Development
	* TripletStore: finished
		* TripletMatrix : finished (with transpose)
		* RowLinkTriMat : public TripletMatrix : finished
	* CrossListStore: finished 
		* CLNode: finished
		* CrossList: finished

## Message Board
Matrix transpose and matrix inversion are not implemented now, which will be added later.




