#include "a_star.h"
#include <iostream>

A_star::A_star(Eigen::MatrixXi _map , Point _start , Point _end){
                                map = _map;
                                start = _start;
                                end = _end;
                                sqrt_2 = 1.414214;
}

double              A_star::cost_G(const Point p){

                            double x_dis = -(start.coordinate[0] - p.coordinate[0]);
                            double y_dis = -(start.coordinate[1] - p.coordinate[1]);
                            return x_dis + 
                                          y_dis + 
                                          (sqrt_2 - 2) * min(x_dis , y_dis);
}


double              A_star::cost_H(const Point p){

                            double x_dis = end.coordinate[0] - p.coordinate[0];
                            double y_dis = end.coordinate[1] - p.coordinate[1];
                            return x_dis + 
                                          y_dis + 
                                          (sqrt_2 - 2) * min(x_dis , y_dis);
}

double              A_star::cost(const Point p){
                            return      cost_G(p) + cost_H(p); 
}

bool                   A_star::is_valid_point(const Point p){
                            if  (p.coordinate[0] < 0 || p.coordinate[1] < 0){
                                            return  false;  
                            }
                            if  (p.coordinate[0] >= map.cols() || p.coordinate[1] >= map.cols()){
                                          return  false;  
                            }
                            return map(p.coordinate[0] , p.coordinate[1]);
}

bool                   A_star::is_point_list(Point p , std::vector <Point> point_list){

                            for (int i = 0 ; i < point_list.size() ; i++ ){
                                                if (point_list[i].coordinate[0] == p.coordinate[0] && 
                                                     point_list[i].coordinate[1] == p.coordinate[1] ){
                                                                    return true;
                                                }
                            }
                            return  false;
}

bool                   A_star::is_open_list(Point p){
                            return      is_point_list(p , open_list);
}

bool                   A_star::is_close_list(Point p){
                            return      is_point_list(p , close_list);
}

bool                   A_star::is_start(Point p){
                            return      (p.coordinate[0] == start.coordinate[0]) && 
                                               (p.coordinate[1] == start.coordinate[1]);
}

bool                   A_star::is_end(Point p){
                            return      (p.coordinate[0] == end.coordinate[0])&&
                                               (p.coordinate[1] == end.coordinate[1]);
}

void                   A_star::process_point(int x , int y , int parent){
                            Point p;
                            p.coordinate[0] = x;
                            p.coordinate[1] = y;

                            if  ( !  is_valid_point(p)){
                                                return;
                            }
                            if  (is_close_list(p)){
                                                return;
                            }
                            if (  !  is_open_list(p)){
                                                p.parent = parent;
                                                p.cost      = cost(p);
                                                open_list.push_back(p);
                            }
}

int                      A_star::select_in_open_list(){

                            int index = 0;
                            double min_cost = -65535;
                            if  (open_list.size() <= 0){
                                            return index-1 ;
                            }
                            for(int i = 0 ; i < open_list.size() ; i++){
                                            if (open_list[i].cost < min_cost){
                                                                min_cost = open_list[i].cost;
                                                                index = i;
                                            }   
                            }
                            return  index;
}

void                   A_star::find_path(){
                            int index = 0;
                            start.cost = 0;
                            open_list.push_back(start);
                            Point p ;
                            while (true){
                                            index = select_in_open_list();
                                            if (index <0){
                                                                std::cout << "No path found, algorithm failed!!!" << std::endl;
                                                                break;;
                                            }
                                            p = open_list[index];
                                            open_list.erase( open_list.begin() + index);
                                            close_list.push_back(p);
                                            if (is_end(p)){ 
                                                                std::cout << "end\n\n\n\n" << std::endl;  
                                                                return; 
                                            }
                                            process_point(p.coordinate[0]      , p.coordinate[1] +1 , close_list.size()-1);
                                            process_point(p.coordinate[0]+1 , p.coordinate[1]       , close_list.size()-1);
                                            process_point(p.coordinate[0]      , p.coordinate[1] - 1 , close_list.size()-1);
                                            process_point(p.coordinate[0]-1 , p.coordinate[1]        , close_list.size()-1);

                                            process_point(p.coordinate[0] +1 , p.coordinate[1] +1 , close_list.size()-1); 
                                            process_point(p.coordinate[0] +1 , p.coordinate[1] -1  , close_list.size()-1);
                                            process_point(p.coordinate[0]  -1 , p.coordinate[1] +1 , close_list.size()-1);
                                            process_point(p.coordinate[0]  -1 , p.coordinate[1] -1  , close_list.size()-1);
                            }
                            
}

void                    A_star::show_path(){

                            Point p = close_list[close_list.size() - 1];
                            do{
                                                std::cout <<"   point       "<< p.coordinate[0]  <<"    "<< p.coordinate[1]   << "\n\n" << std::endl;
                                                p = close_list[p.parent];
                            }while(! ((p.coordinate[0] == start.coordinate[0])&&
                                             (p.coordinate[1] == start.coordinate[1])));
                            std::cout << start.coordinate <<std::endl;

                             

}







int min(int x , int y){
                if ( x > y ){       return      x ;     }
                return      y;
}