<!DOCTYPE html>
<html>
  <head>
    <meta charset="utf-8">
    <title>My first Three.js app</title>
    <style>
      body { margin: 0; }
      canvas { width: 100%; height: 100% }
    </style>
  </head>
  <body>

    <script src="https://ajax.googleapis.com/ajax/libs/threejs/r69/three.min.js"></script>

    <script>
      var scene = new THREE.Scene()
      var camera = new THREE.PerspectiveCamera(
        75, window.innerWidth / window.innerHeight,
        0.1, 1000
      )
      var renderer = new THREE.WebGLRenderer()
      renderer.setSize(window.innerWidth, window.innerHeight)
      document.body.appendChild(renderer.domElement)

      var geometry = new THREE.BoxGeometry(1, 1, 1)
      var material = new THREE.MeshBasicMaterial()

      var directionalLight = new THREE.DirectionalLight(0xe1e2ff)
      directionalLight.position.set(2, 5, 4)
      scene.add(directionalLight)

      var sphere = new THREE.Mesh(
        new THREE.SphereGeometry(0.8, 32, 24),
        new THREE.MeshLambertMaterial({ color: 0x12ff34 })
      )
      scene.add(sphere)

      var cube = new THREE.Mesh(
        new THREE.BoxGeometry(0.8, 0.8, 0.8),
        new THREE.MeshBasicMaterial({ color: 0xff1234 })
      )
      scene.add(cube)

      camera.position.z = 5

      var movingLeft = true
      var movingRight = true

      var render = function() {
        requestAnimationFrame(render)

        if (sphere.position.x >= 4) {
          movingLeft = false
          movingRight = true
        }

        if (sphere.position.x <= -4) {
          movingLeft = true
          movingRight = false
        }

        if (movingLeft) {
          sphere.position.x += 0.05
          sphere.position.y -= 0.03
          sphere.rotation.x -= 0.05

          cube.rotation.y += (Math.random() * Math.random()) / 10
        } else if (movingRight) {
          sphere.position.x -= 0.05
          sphere.position.y += 0.03
          sphere.rotation.x += 0.05

          cube.rotation.x += (Math.random() * Math.random()) / 10
        }

        renderer.render(scene, camera)
      }

      render()
    </script>

  </body>
</html>
