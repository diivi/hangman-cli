# CLI for the hangman game
## <u>Screenshots</u>
![welcome screenshot](/img/ss.png)
## <u>Demos</u>
### failed attempt with genre set to animals
![failure demo](/img/fail.gif)
### succesful attempt with genre set to sports
![success demo](/img/success.gif)

<br>

# Details
100% C Code.
Fetches data related to a genre from the [DataMuse](https://www.datamuse.com/api/) API and gives a random word (currently) from the JSON to the user to guess. Later versions will prefer words based on difficulty and relevance.

# Requirements
1. CURL
`sudo apt-get install libcurl4-openssl-dev`

2. libjansson-dev
`sudo apt-get install -y libjansson-dev`

# Compile
`gcc hangman.c -o hangman -lcurl -ljansson`

# Run
Download the linux executable `hangman` and run
`chmod +x hangman` to make it executable. Then run it with `./hangman`

gcc hangman.c -o hangman2 -lcurl -ljansson



### TODO
- [ ] loop and points
- [ ] set difficulty
- [ ] better api?
- [ ] offline support for specific topics only
