// #include <ranges>
#include <vector>
#include <algorithm> 

#include "movie.h"


int main()
{
	std::vector<Movie> movies{Movie{"The Green Mile", 9.2},
		Movie{"Schindler's List", 9.1},
		Movie{"The Shawshank Redemption", 9.0},
		Movie{"Forrest Gump", 9.0},
		Movie{"Interstellar", 8.8},
		Movie{"1+1", 8.8},
		Movie{"The Dark Knight", 8.8},
		Movie{"Fight Club", 8.7},
		Movie{"Shrek", 8.7},
		Movie{"The Lord of the Rings: The Fellowship of the Ring", 8.6},
		Movie{"Aliens", 8.2},
		Movie{"Eternal Sunshine of the Spotless Mind", 8.1}
	};

	auto items = std::views::zip(movies, std::views::ints(1)) |
		std::views::transform([](const auto& pair)
			{return std::to_string(pair.second + ": " + pair.first.name)})

}