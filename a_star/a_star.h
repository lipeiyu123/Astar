#ifndef      __A_STAR_H__
#define     __A_STAR_H__

#include <Eigen/Dense>
#include <vector>

typedef struct Point{
                Eigen::Vector2i coordinate;
                int                          parent;
                double                 cost;
};


class       A_star{

                 public:
                                                            A_star(Eigen::MatrixXi _map , Point _start , Point _end);
                                void                   find_path();
                                void                    show_path();

                private:         
                                std::vector <Point> open_list;
                                std::vector <Point> close_list;  

                                Point                  start;
                                Point                  end;     
                                Eigen::MatrixXi map;
                                double              sqrt_2;

                                double              cost_G(const Point p);
                                double              cost_H(const Point p);
                                double              cost(const Point p);
                                bool                   is_valid_point(const Point p);
                                bool                   is_point_list(Point p , std::vector <Point> point_list);
                                bool                   is_open_list(Point p);
                                bool                   is_close_list(Point p);
                                bool                   is_start(Point p);
                                bool                   is_end(Point p);
                                void                   process_point(int x , int y , int parent);
                                int                      select_in_open_list(); 

};

int         min(int x , int y);

#endif