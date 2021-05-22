#include "Player.h"

Player::Player()
{

}

Player::~Player()
{

}

void Player::setTeam(const string& team)
{

}

void Player::setCurrentState(const Board& currentState)
{

}

string Player::getTeam() const
{
    return team;
}

Board Player::getCurrentState() const
{
    return currentState;
}

void Player::resign()
{

}

Board Player::makeMove(const string& startCoordinate, const string& finishCoordinate)
{
    return currentState;
}
