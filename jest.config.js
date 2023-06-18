export default {
  testEnvironment: 'node',
  
  transform: {
    '^.+\\.js?$': 'babel-jest',
  },

  transformIgnorePatterns: [
    '/node_modules/*',
  ],
  
}
