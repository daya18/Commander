#pragma once

#include <string>

#include "nlohmann/json.hpp"

namespace cmdr
{
	class Command
	{
	public:
		Command ( nlohmann::json const & );
		Command ( std::string const & name, std::string const & command );

		std::string const & GetName () const;
		std::string const & GetCommand () const;

		void Execute () const;

		nlohmann::json ToJSON () const;

	private:
		std::string name;
		std::string command;
	};



	// Implementation
	inline std::string const & Command::GetName () const
	{
		return name;
	}

	inline std::string const & Command::GetCommand () const
	{
		return command;
	}
}