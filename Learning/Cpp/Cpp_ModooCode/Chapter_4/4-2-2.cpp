#include <iostream>
#include <cmath>

class Point {
	int x, y;

public:
	Point(int pos_x, int pos_y) : x(pos_x), y(pos_y)
	{ }

	int GetX() const { return x; }
	int GetY() const { return y; }
};

class Geometry {
private:
	Point* point_array[100];	// 점 100개를 보관하는 배열
	int num_points;
public:
	Geometry() : num_points(0)
	{ }
	~Geometry() 
	{
        for (int i = 0; i < num_points; i++)
            delete point_array[i];
    }
	void AddPoint(const Point& point) {
		point_array[num_points++] = new Point(point.GetX(), point.GetY());
	}

	// 모든 점들 간의 거리를 출력하는 함수입니다.
	void PrintDistance();

	// 모든 점들을 잇는 직선들 간의 교점의 수를 출력해주는 함수입니다.
	void PrintNumMeets();
};

void Geometry::PrintDistance()
{
	for (int i = 0; i < num_points-1; i++)
	{
		for (int j = i + 1; j < num_points; j++)
		{
			std::cout << i + 1 << "번째 점과 " << j + 1 << "번째 점 사이의 거리는 "
				<< sqrt(pow(point_array[i]->GetX() - point_array[j]->GetX(), 2)+ pow(point_array[i]->GetY() - point_array[j]->GetY(), 2))<<"입니다.\n";
		}
	}
}

void Geometry::PrintNumMeets()
{
    // 만들 수 있는 직선은 총 num_points*(num_points-1)/2 개이다.
    // 직선의 방정식 계수 a, b, c를 0으로 초기화
    // 직선의 방정식 : a*x + b*y + c = 0    
    const int NUM_OF_LINES = num_points*(num_points-1)/2;

    // 첫번째[0] : 직선의 방정식 계수 a
    // 두번째[1] : 직선의 방정식 계수 b
    // 세번째[2] : 직선의 방정식 계수 c
    // 네번째[3] : 직선의 방정식을 만드는 point1의 index
    // 다섯번째[4] : 직선의 방정식을 만드는 point2의 index
    int coefficients[100000][5] = {0, };

    if (NUM_OF_LINES > 100000)
	{
        std::cout << "직선의 개수가 너무 많아 계산이 불가합니다." << std::endl;
        return;
    }

    // 직선의 방정식 계수 a, b, c를 구한다.
    int x1 = 0, y1 = 0;
    int x2 = 0, y2 = 0;
    int nth_line = 0;
    for (int i = 0; i < num_points -1; i++) {
        for (int j = 0; j < num_points; j++) {
            x1 = point_array[i]->GetX();
            y1 = point_array[i]->GetY();
            x2 = point_array[j]->GetX();
            y2 = point_array[j]->GetY();

            coefficients[nth_line][0] = y2 - y1; // a
            coefficients[nth_line][1] = x1 - x2; // b
            coefficients[nth_line][2] = x1*y1 - 2*x1*y2 + x2*y2; // c
            coefficients[nth_line][3] = i;
            coefficients[nth_line][4] = j;
            nth_line++;
        }
    }


    // 직선이 만나는 포인트의 개수를 구한다.
    int sum_of_meets = 0;
    for (int i = 0; i < NUM_OF_LINES; i++) {
        for (int j = 0; j < num_points - 1; j++) {
            for (int k = j+1 ; k < num_points; k++) {
                // 직선의 방정식을 세운 포인트는 넘어가기
                if (coefficients[i][3] == j || coefficients[i][3] == k) {
                    continue;
                }

                x1 = point_array[j]->GetX();
                y1 = point_array[j]->GetY();
                x2 = point_array[k]->GetX();
                y2 = point_array[k]->GetY();
                
                // 두 포인트가 직선 기준으로 서로 반대면에 있는지 확인
                if ((coefficients[i][0]*x1 + coefficients[i][1]*y1 + coefficients[i][2]) * (coefficients[i][0]*x2 + coefficients[i][1]*y2 + coefficients[i][2]) <= 0) {
                    sum_of_meets++;
                }
            }
        }
    }   

    std::cout << std::endl;
    std::cout << "직선의 개수는 " << NUM_OF_LINES << "개 입니다." << std::endl;
	if(sum_of_meets%2!=0)
    	std::cout << "직선의 방정식이 교차하는 점의 개수는 " << sum_of_meets/2 + 1 << "개 이다." << '\n';
	else
		std::cout << "직선의 방정식이 교차하는 점의 개수는 " << sum_of_meets/2 << "개 이다." << '\n';
}



int main() {
	// 테스트
	Point pos1(1, 2), pos2(3, 1), pos3(-1, -4), pos4(5,2);
	Geometry Geo;
	Geo.AddPoint(pos1);
	Geo.AddPoint(pos2);
	Geo.AddPoint(pos3);
	Geo.AddPoint(pos4);
	
	Geo.PrintDistance();
	Geo.PrintNumMeets();

	return 0;
}