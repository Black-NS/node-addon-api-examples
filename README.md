# node-addon-api-examples
node-addon-api-examples

## project running
```
npm install
cd ${project name}
make
```

- make clean - delete build file
- make configure - node-gyp configure command run
- make build - node-gyp configure and build command run
- make run - node-gype test.js running


## project list
- hello - first nodejs library, print only string
- hello_class - using c++ class, print only string, no argument 
- echo - ouputting echo messages using asyncworker(
### NOTE
https://nodejs.github.io/node-addon-examples/special-topics/asyncworker/
)