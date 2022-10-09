var tag = document.createElement('script');

      tag.src = "https://www.youtube.com/iframe_api";
      var firstScriptTag = document.getElementsByTagName('script')[0];
      firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);

      // 2. This function creates an <iframe> (and YouTube player)
      //    after the API code downloads.
      var player;
      function onYouTubeIframeAPIReady() {
        player = new YT.Player('player', {
          height: '390',
          width: '640',
          // replace the Bw5a4X8YJlk video ID below with the video ID of your chosen YouTube video
          videoId: 'v7MYOpFONCU',
          playerVars: { 'controls': 1 },
          events: {
            'onReady': onPlayerReady,
            'onStateChange': onPlayerStateChange
          }
        });
      }

      // 3. The API will call this function when the video player is ready.
      function onPlayerReady(event) {
        event.target.playVideo();
      }

      // 4. The API calls this function when the player's state changes.
      //    The function indicates that when playing a video (state=1),
      //    the player should play for ten seconds and then stop.
      var done = false;
      function onPlayerStateChange(event) {
        if (event.data == YT.PlayerState.PLAYING && !done) {
          setTimeout(pauseVideo, 10000);
          done = true;
        }
      }
      //function stopVideo() {
       // player.stopVideo();
      //}
      function pauseVideo() {
        player.pauseVideo();
      }