#include "Account.hpp"
#include <chrono>
#include <iomanip>
#include <iostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit)
{
	this->_amount = initial_deposit;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_totalAmount += this->_amount;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}

Account::~Account( void )
{
	Account::_displayTimestamp();
	this->_nbAccounts--;
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

void 	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_nbDeposits++;
	this->_totalNbDeposits++;
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << ";" << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	if (withdrawal > this->_amount)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return false;
	}
	this->_amount -= withdrawal;
	this->_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	this->_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << ";" << std::endl;
	return true;
}

void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;

}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t time = std::time(nullptr);
	std::cout << "[";
	std::cout << std::put_time(std::localtime(&time), "%Y%m%j_%H%M%S");
	std::cout << "] ";
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}

int		Account::getNbAccounts(void)
{
	return Account::_nbAccounts;
}
int		Account::getTotalAmount(void)
{
	return Account::_totalAmount;
}
int		Account::getNbDeposits(void)
{
	return Account::_totalNbDeposits;
}
int 	Account::getNbWithdrawals(void)
{
	return Account::_totalNbWithdrawals;
}

Account::Account( void )
{
	this->_amount = 0;
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
}