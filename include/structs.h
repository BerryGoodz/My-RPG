#ifndef STRUCTS_H
#define STRUCTS_H

struct image
    {
        explicit image(std::string s)
        :imgName(s){}
        std::string imgName;

    };
struct setRect
    {
        explicit setRect(int x1, int y1, int x2, int y2)
        {
            x = x1;
            y = y1;
            rectX = x2;
            rectY = y2;
        }
        int x;
        int y;
        int rectX;
        int rectY;

    };
struct position
{
    explicit position(int x, int y)
    {
        x1 = x;
        y1 = y;
    }
    int x1;
    int y1;
};
struct entityNames
{
    explicit entityNames(std::string s)
    :name(s){}
    std::string name;
};
struct charSize
{
    explicit charSize(float n)
    :s(n){}
    float s;
};
struct rectSize
{
    explicit rectSize(float x1, float y1)
    {
        x = x1;
        y = y1;
    }
    float x;
    float y;
};
struct health
{
    explicit health(int n)
    :h(n){}
    int h;
};
struct eva
{
    explicit eva(int n)
    :a(n){}
    int a;
};
struct ID
{
    explicit ID(int a)
    :n(a){}
    int n;
};
#endif // STRUCTS_H
