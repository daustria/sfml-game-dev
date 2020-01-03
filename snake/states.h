#ifndef CELL_STATES_H
#define CELL_STATES_H
#include <memory>
#include <SFML/Graphics.hpp>
class Cell;
enum class Direction{Up, Down, Left, Right};

class CellState
{
	public:
		virtual ~CellState() = default;
		virtual void snake(std::shared_ptr<Cell>, Direction) {}
		virtual void food(std::shared_ptr<Cell>) {} 
		virtual void normal(std::shared_ptr<Cell>) {}
};

class Normal : public CellState
{
	public:
		virtual ~Normal() = default;
		virtual void snake(std::shared_ptr<Cell>, Direction) override;
		virtual void food(std::shared_ptr<Cell>) override;
};

class Snake : public CellState
{
	public:
		Snake(Direction);
		virtual ~Snake() = default;
		virtual void normal(std::shared_ptr<Cell>) override;
		void changeDir(Direction d);
		Direction dir();
	private:
		Direction dir_;
};

class Food : public CellState
{
	public:
		virtual ~Food() = default;
		virtual void normal(std::shared_ptr<Cell>) override;
		virtual void snake(std::shared_ptr<Cell>, Direction) override;
};
#endif //CELL_STATE_H
