
#include <iostream>
#include "a_star/a_star.h"

#define     E    true
#define     O   false


int main(){

                    Eigen::MatrixXi     map(6 , 6);
                    map    <<      E , E , E , E , E , E,                       //v   X     > Y
                                            E , E , O, E , E , E ,
                                            E , E , O , E , E , E ,
                                            E , E , O , O , O , O ,
                                            E , E , E , E , E , E,
                                            E , E , E , E , E , E;
                    std::cout << "map size" << map.cols() <<std::endl;
                    Point   start;
                    Point   end;
                    start.coordinate[0] = 4;
                    start.coordinate[1] = 1;
                    end.coordinate[0] = 2;
                    end.coordinate[1] = 4;
                    A_star a_star(map , start , end);
                    a_star.find_path();
                    std::cout << "run here" << std::endl;
                    a_star.show_path();

                    return 0;
}