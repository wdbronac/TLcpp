#include <blkOver.hpp>
#include <string>



blk::Expr blk::over( blk::Expr e1, blk::Expr e2) {
  // This raises a compilation error since Over constructor is private
  // return std::make_shared<Over>(symb,width,height,ref_width,ref_height); 
  return blk::Expr(new blk::Over::Over(e1, e2));
}

blk::Over::Over( blk::Expr e1, blk::Expr e2) :
   blk::Block::Block(
           getSize(e1,e2),
           e1->getHeight() + e2->getHeight(),
           std::max(e1->getRefWidth(), e2->getRefWidth()),
           e1->getRefHeight()
           ),
          exp1(e1),
          exp2(e2)
   {}
   
int blk::Over::getSize(blk::Expr e1, blk::Expr e2){
return  std::max(e1->getWidth()-e1->getRefWidth(), e2->getWidth()-e2->getRefWidth()) + std::max(e1->getRefWidth(), e2->getRefWidth()) ;
}


void blk::Over::spePrint(std::ostream& os,const blk::Expr& e1, int i,int L, int L2) {
        int l = e1->getRefWidth();
        int l2 = e1->getWidth()-e1->getRefWidth();
        if (l<L){
            os <<std::string(L-l,blk::Block::fill);
        }
        e1->blk::Block::printLine(os, i);
        if (l2<L2){
            os <<std::string(L2-l2,blk::Block::fill);
        }
    }

void blk::Over::printInBoundsLine(std::ostream& os, int i) const {

    int L = getRefWidth();
    int L2 = getWidth()-getRefWidth();
    if (i<exp1->getHeight()-exp1->getRefHeight()){
        blk::Over::spePrint(os,exp1,i,L,L2);
    }
    if (((exp1->getHeight()-exp1->getRefHeight())<=i)&&(i<=getHeight())){
        blk::Over::spePrint(os,exp2,i-(exp1->getHeight()-exp1->getRefHeight())-exp2->getRefHeight(),L,L2);
    }
}


