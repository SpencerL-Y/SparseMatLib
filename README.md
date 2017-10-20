# Sparse Matrix Library For Demonstration
- **Environment**: Windows 10 15063.296
- **Compiler**: g++ [-std=c++11]
- **IDE**: Codeblocks 16.01
- **Status**: Completed (not responsible for any bugs that may remain)

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
Matrix transpose and matrix inversion (iterative version) are not implemented now; will be added later.
