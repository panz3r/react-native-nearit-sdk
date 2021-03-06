var postlinks = [
  require('./postlink.ios'),
  require('./postlink.android')
]

// run them sequentially
postlinks
  .reduce((p, fn) => p.then(fn), Promise.resolve())
  .catch((err) => {
    console.error(err.message)
  })
