/*-----------------------------------------------------------------------------------------------
 * CLASS NAME: CLNode
 *
 * Author: Clexma
 * Institute: UCAS
 * Created: 6/7/2017
 * Last Modified: 6/14/2017
 -----------------------------------------------------------------------------------------------*/

#ifndef CLNODE_H
#define CLNODE_H
#include <iostream>
#include <vector>
#include <memory>
namespace MatLib
{



namespace CrossListStore
{



class CLNode
{
    public:
        CLNode();
        CLNode(unsigned int row, unsigned int col, int val);
        virtual ~CLNode();
        void modifyNode(unsigned int row, unsigned int col, int val);
        void createDownNode(unsigned int row, unsigned int col, int val);
        void createRightNode(unsigned int row, unsigned int col, int val);
        void deleteDownNode();
        void deleteRightNode();

        void printNode() const;
        void printRightList() const;
        void printDownList() const;
        void printRightListVal(unsigned int hgt) const;

        unsigned int getRowNum() const;
        unsigned int getColNum() const;
        int getVal() const;

        void operator=(const CLNode &N);
        std::shared_ptr<CLNode> down;
        std::shared_ptr<CLNode> right;
    protected:
        unsigned int rowNum;
        unsigned int colNum;
        int value;
    private:
};


}


}
#endif // CLNODE_H
