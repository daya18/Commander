#include "Command.hpp"

#include <thread>

namespace cmdr
{
	Command::Command ( nlohmann::json const & json )
		: name ( json["Name"] ), command ( json ["Command"] )
	{
	}

	Command::Command ( std::string const & name, std::string const & command )
		: name ( name ), command ( command )
	{
	}

	nlohmann::json Command::ToJSON () const
	{
		nlohmann::json json;
		json [ "Name" ] = name;
		json [ "Command" ] = command;
		return json;
	}

	void Command::Execute () const
	{		
		if ( command.empty () )
			return;

		std::thread thread { [ this ] () { system ( command.data () ); } };
		thread.detach ();
	}
}