#include "Calendar.h"

void Calendar::addEvent (const Event &event) const
{
    events->push_back(event);
}

void Calendar::updateEvent (time_t old_date, const std::string& old_name,
                            time_t new_date, const std::string& new_name) const
{
    bool found = false;
    for (std::vector<Event>::iterator it = events->begin();
         it != events->end() && !found; ++it)
    {
        if (it->getTime() == old_date && it->getName() == old_name)
        {
            found = true;
            it->setTime(new_date);
            it->setName(new_name);
        }
    }
}

void Calendar::print() const 
{
    for (const Event &e : *events)
        std::cout << e.getName() << std::endl;
}
