#include <stdlib.h>
#include <stdio.h>
#include <time.h>

struct Vertex3f
{
    float x, y, z;
};

struct Player
{
private:
    float speed;
public:

    Vertex3f pos;

    Player(float _speed)
    {
        speed = _speed;
    }
};

void setValues(Vertex3f* ptrV3)
{
    ptrV3->x = (float)(rand() % 1000);
    ptrV3->y = (float)(rand() % 1000);
    ptrV3->z = (float)(rand() % 1000);
}

Vertex3f posPlayer(float speed)
{

    return {};
}

int main()
{
    srand((unsigned int)time(NULL));

    Vertex3f vertex;
    Player player(10);

    unsigned char id = 0;
  
    printf("Insert how many points you want to generate 255\n");
    scanf("%hhd", &id);

    Vertex3f* vertexBuffer = (Vertex3f*)malloc(id * sizeof(Vertex3f));

    for (int i = 0; i < id; i++)
    {
        setValues(&vertexBuffer[i]);

        printf("COORDINATE %3d = [X: %7.3f || Y: %7.3f || Z: %7.3f]\n", i, vertexBuffer[i].x, vertexBuffer[i].y, vertexBuffer[i].z);
    }

    free(vertexBuffer);

    return 0;
}